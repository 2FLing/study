#include "pch.h"
#include "framework.h"
#include "LANClient.h"
#include "LANClientDlg.h"
#include "afxdialogex.h"
#include<locale>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


HWND CLANClientDlg::hwnd = NULL;

CLANClientDlg::CLANClientDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LANCLIENT_DIALOG, pParent)
	, m_name(_T(""))
	, isCon(false)
	, m_et_Msg(_T(""))
	, isSet(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLANClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IP_ADDR, m_ip);
	DDX_Text(pDX, IDC_ET_NAME, m_name);
	DDX_Control(pDX, IDC_LS_MEMBER, m_Member);
	DDX_Text(pDX, IDC_ET_SHOWMSG, m_et_Msg);
	DDX_Control(pDX, IDC_ET_SHOWMSG, m_showMSg);
}

unsigned __stdcall CLANClientDlg::RecvMsg(void* param)
{
	CTcpClient* cli = (CTcpClient*)param;
	while (1) {
		char* buf = new char[0xFF]{};
		int len=cli->Recv(buf,0xFF);
		if (len <= 0) {
			::PostMessageW(hwnd, UM_MODIUSER, 0, (LPARAM)buf); 
			break;
		}
		::PostMessageW(hwnd, UM_MODIUSER, 1, (LPARAM)buf);
	}
	return 0;
}

BEGIN_MESSAGE_MAP(CLANClientDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CNT, &CLANClientDlg::OnBnClickedBtnCnt)
	ON_BN_CLICKED(IDC_BTN_SEND, &CLANClientDlg::OnBnClickedBtnSend)
	ON_MESSAGE(UM_MODIUSER, &CLANClientDlg::OnUmSelSevMsg)
	ON_BN_CLICKED(IDC_BTN_SET, &CLANClientDlg::OnBnClickedBtnSet)
END_MESSAGE_MAP()

BOOL CLANClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);
	ShowWindow(SW_NORMAL);
	if (!CTcpClient::InitNet()) {
		AfxMessageBox(L"Failed to initialized web environment");
	}
	if (!m_client.Create()) {
		AfxMessageBox(L"Failed to create client");
	}
	m_ip.SetAddress(127, 0, 0, 1);
	hwnd = m_hWnd;
	SetDlgItemInt(IDC_ET_PORT,3000);
	setlocale(LC_ALL, "");
	return TRUE;
}

void CLANClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CLANClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLANClientDlg::OnBnClickedBtnCnt()
{
	if (isCon) {
		m_client.Close();
		isCon = false;
		AfxMessageBox(L"Disconnect Succefully");
		SetDlgItemText(IDC_BTN_CNT, _T("Connect"));
		m_Member.DeleteAllItems();
		return;
	}
	if (!m_client.IsValid()) {  
		m_client.Create();
	}
	UpdateData();
	if (m_name.IsEmpty()) {
		AfxMessageBox(L"Please enter your name");
		return;
	}


	DWORD ip;
	m_ip.GetAddress(ip);
	int port = GetDlgItemInt(IDC_ET_PORT);

	if (!m_client.Connect(port,ip)) {
		AfxMessageBox(L"Failed to connect server");
		return;
	}
	
	m_Member.InsertItem(0, m_name);
	SetDlgItemText(IDC_BTN_CNT, _T("Connect successfully"));
	_beginthreadex(0, 0, RecvMsg, &m_client, 0, 0);
	SetDlgItemText(IDC_BTN_CNT, _T("Disconnect"));
	isCon = true;
	USES_CONVERSION;
	std::string na = W2A(m_name);
	m_client.Send(na.data(), na.size());
}


void CLANClientDlg::OnBnClickedBtnSend()
{
	if (!m_client.IsValid()) {
		SetDlgItemText(IDC_BTN_SEND, _T("Internet Error"));
		SetDlgItemText(IDC_BTN_SEND, _T("Send"));
		return;
	}
	CString msg;
	GetDlgItemText(IDC_ET_MSG, msg);
	if (msg.IsEmpty()) {
		SetDlgItemText(IDC_BTN_SEND, _T("Empty Message"));
		SetDlgItemText(IDC_BTN_SEND, _T("Send"));
		return;
	}
	UpdateData();
	USES_CONVERSION;
	std::string str = W2A(msg);
	int len=m_client.Send(str.data(), str.size());
	if (len == str.size()) {
		msg = _T("yourself: ") + msg + _T("\r\n");
		m_et_Msg.Append(msg);
		SetDlgItemText(IDC_ET_MSG, _T(""));
		UpdateData(false);
	}
	
	m_showMSg.LineScroll(m_showMSg.GetLineCount() - 10);
}


afx_msg LRESULT CLANClientDlg::OnUmSelSevMsg(WPARAM wParam, LPARAM lParam)
{
	if (!wParam) {
		char* msg = (char*)lParam;
		delete[] msg;
		UpdateData();
		m_et_Msg.Append(_T("You are disconnected\r\n"));
		UpdateData(false);
		m_Member.DeleteAllItems();
		return -1;
	}

	char* msg = (char*)lParam;
	if (msg[0] == '1' && msg[1] == ':') {
		USES_CONVERSION;
		CString s = A2W(&msg[2]);
		UpdateData();
		m_et_Msg.Append(s + L"\r\n");
		UpdateData(false);
		int index = s.Find(L':');
		s.GetBuffer()[index] = L'\0';
		m_Member.InsertItem(0,s);
	}
	else if (msg[0] == '2' && msg[1] == ':') {
		USES_CONVERSION;
		CString s = A2W(&msg[2]);
		UpdateData();
		m_et_Msg.Append(s + L"\r\n");
		UpdateData(false);
		int index = s.Find(L':');
		s.GetBuffer()[index] = L'\0';
		for (int i = 0; i < m_Member.GetItemCount(); i++) {
			if (m_Member.GetItemText(i, 0)==s) {
				m_Member.DeleteItem(i);
				break;
			}
		}
	}
	else if (msg[0] == '3' && msg[1] == ':') {
		USES_CONVERSION;
		CString s = A2W(&msg[2]);
		UpdateData();
		m_et_Msg.Append(s + L"\r\n");
		UpdateData(false);
	}
	else if (msg[0] == '4' && msg[1] == ':') {
		USES_CONVERSION;
		CString s = A2W(&msg[2]);
		int index = 0;
		for (int i = 0; i < s.GetLength(); i++) {
			if (s[i] == L':') {
				s.GetBuffer()[i] = L'\0';
				m_Member.InsertItem(0, &s.GetBuffer()[index]);
				index = i + 1;
			}
		}
		
	}
	m_showMSg.LineScroll(m_showMSg.GetLineCount() - 10);
	delete[] msg;
	return 0;
}


void CLANClientDlg::OnBnClickedBtnSet()
{
	if (isSet)
	{
		RECT rect;
		GetWindowRect(&rect);
		rect.right += 360;
		MoveWindow(&rect);
	}
	else 
	{
		RECT rect;
		GetWindowRect(&rect);
		rect.right -= 360;
		MoveWindow(&rect);
	}
	isSet = !isSet;
}

