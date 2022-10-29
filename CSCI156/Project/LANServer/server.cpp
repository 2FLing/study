#define  _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<map>
#include"CNetServer.h"
using std::map;
using std::cout;
using std::endl;
using std::pair;
map<CTcpOfClient*, string> m_clients; 
DWORD  WINAPI RecvMSG(LPVOID param); 

int main() {
	if (!CTcpListen::InitNet()) {
		cout << "";
		return -1;
	}
	CTcpListen sockServer; 
	if (!sockServer.Create()) {
		cout << "";
		return -1;
	}
	if (!sockServer.Bind(3000)) {
		cout << "";
		return -1;
	}
	if (!sockServer.Listen()) {
		cout << "";
		return -1;
	}
	cout << "" << endl;

	while (true) {
		CTcpOfClient *cli=new CTcpOfClient; 
		if (!sockServer.Accept(*cli)) { 
			cout <<cli->GetIp() << "" << endl;
			continue;
		}
		char msg[20]{};
		int len=cli->Recv(msg,20);
		if (len <= 0) {
			cout << cli->GetIp() << "" << endl;
			delete cli;
			continue;
		}

		m_clients.insert(pair<CTcpOfClient*, string>(cli, msg)); 
		cout << msg << "  entered the room" << endl;
		CreateThread(0, 0, RecvMSG, cli, 0, 0);
	}
	CTcpListen::ClearNet();

}

DWORD  WINAPI RecvMSG(LPVOID param)
{
	CTcpOfClient* cli = (CTcpOfClient*)param; 
	for (auto& i : m_clients) {
		if (i.first == cli) continue; 
		string tm = "1:"; 
		tm += m_clients[cli];
		i.first->Send(tm.data(), tm.size()); 
	}
	string tn = "4:"; 
	for (auto& i : m_clients) { 
		if (i.first == cli) continue;
		tn += (i.second + ":");
	}

	cli->Send(tn.data(), tn.size()); 
	char msg[0xFF]{}; 
	while (1) {
		int len = cli->Recv(msg, 0xFF);
		if (len > 0) {
			for (auto& i : m_clients) {
				if (i.first == cli) continue;
				string tm = "3:" + m_clients[cli] + ':'; 
				tm += msg;
				i.first->Send(tm.data(), tm.size());
			}
			continue;
		}
		for (auto& i : m_clients) {
			if (i.first == cli) continue;
			string exitMsg = "2:"; 
			exitMsg += (m_clients[cli] + " left the room");
			i.first->Send(exitMsg.data(), exitMsg.size());
		}
		cout << m_clients[cli] << " left the room" << endl; 
		m_clients.erase(cli);
		delete cli; 
		break; 
	}

	return 0;
}