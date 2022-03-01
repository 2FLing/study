#include<iostream>
#include<string>
#include<stdio.h>
#include<time.h>
using namespace std;
string fib_re(int);
string fib_iter(int);
string add(string, string);
int main()
{
	float start_iter, end_iter, start_re,end_re;
	start_iter = clock();
	cout <<fib_iter(120) << endl;
	end_iter = clock();
	cout << "The iterative algorithm takes "<<(end_iter - start_iter) / CLOCKS_PER_SEC << " to finish."<<endl;
	start_re = clock();
	cout << fib_re(120) << endl;
	end_re = clock();
	cout << "The recursion algorithm takes " << (end_re - start_re) / CLOCKS_PER_SEC << " to finish." << endl;
	return 0;
}

string fib_re(int N)
{
	if (N == 0 or N == 1)
		return to_string(N);
	else
		return add(fib_re(N - 1),fib_re(N - 2));
}

string fib_iter(int N)
{
	if (N == 0 or N == 1)
		return to_string(N);
	else
	{
		string pre = "0", cur = "1", temp;
		for (int i = 1; i < N; i++)
		{
			temp = cur;
			cur = add (cur,pre);
			pre = temp;
		}
		return cur;
	}
}
string add(string num1, string num2)
{
	string res="", digit;
	int i = num1.size()-1, j = num2.size()-1;
	int mover = 0,temp1,temp2,sum;
	while (i >= 0 and j >= 0)
	{
		temp1 = num1[i--] - '0';
		temp2 = num2[j--] - '0';
		sum = (temp1 + temp2 + mover) % 10;
		mover = (temp1 + temp2+mover) / 10;
		digit = to_string(sum);
		res = digit + res;
	}
	while (i >= 0)
	{
		temp1 = num1[i--]-'0';
		sum = (temp1+ mover)%10;
		mover = (temp1 + mover) / 10;
		digit = to_string(sum);
		res = digit + res;
		if (mover == 0)
			break;
	}
	while (j >= 0)
	{
		temp1 = num2[j--] - '0';
		sum = (temp1 + mover) % 10;
		mover = (temp1 + mover) / 10;
		digit = to_string(sum);
		res = digit + res;
		if (mover == 0)
			break;
	}
	if (mover != 0)
		res = to_string(mover) + res;
	return res;
}