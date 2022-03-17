#ifndef _COUNTINGSORT
#define _COUNTINGSORT
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;
void counting_sort(vector<int>&);
int find_max(vector<int>);
vector<int> create_vector();
void print_vector(vector<int>);
void radix_sort(vector<int>&);
int count_digits(int);
vector<int> crazy_vector();
vector<int>in_order_vector();
void counting_sort(vector<int>& v)
{
	if (v.size()> 0)
	{
		int max = find_max(v);
		vector<int>auxiliary, new_v;
		for (int i = 0; i <= max; i++)
			auxiliary.push_back(0);
		for (int i = 0; i < v.size(); i++)
		{
			auxiliary[v[i]]++;
		}
		for (int i = 1; i < auxiliary.size(); i++)
		{
			int sum = auxiliary[i - 1];
			auxiliary[i] += sum;
		}
		for (int i = 0; i < v.size(); i++)
		{
			new_v.push_back(0);
		}
		for (int i = v.size() - 1; i >= 0; i--)
		{
			new_v[auxiliary[v[i]] - 1] = v[i];
			auxiliary[v[i]]--;
		}
		v = new_v;
	}
}
void radix_sort(vector<int>& v)
{
	int max = find_max(v);
	int digits = count_digits(max);
	vector<int>new_v;
	for (auto ele : v)
		new_v.push_back(ele);
	for (int i = 0; i < digits; i++)
	{
		vector<int>auxiliary;
		for (int k = 0; k < 10; k++)
			auxiliary.push_back(0);
		for (int j = 0; j < v.size(); j++)
		{
			int tmp = v[j] / pow(10, i);
			int digit = tmp % 10;
			auxiliary[digit]++;
		}
		for (int j = 1; j < auxiliary.size(); j++)
			auxiliary[j] += auxiliary[j - 1];
		for (int j = v.size()-1; j >=0; j--)
		{
			int tmp = v[j] / pow(10, i);
			int digit = tmp % 10;
			new_v[auxiliary[digit] - 1] = v[j];
			auxiliary[digit]--;
		}
		v = new_v;
	}

}
int find_max(vector<int>v)
{
	if (v.size() > 0)
	{
		int max = v[0];
		for (auto ele : v)
		{
			if (ele > max)
				max = ele;
		}
		return max;
	}
	else
		return -1;
}
vector<int> create_vector()
{
	vector<int> nums;
	string str,tmp="";
	int digit=0,num=0;
	cout << "Please enter a list of numbers(separate numbers by space): ";
	getline(cin, str);
	str += " ";
	for (int i = 0; i <str.size(); i++)
	{
		if (str[i] != ' ')
		{
			tmp.push_back(str[i]);
		}
		else
		{
			for (int j = tmp.size() - 1; j >= 0; j--)
			{
				num += (tmp[j] - '0') * pow(10, digit);
				digit++;
			}
			nums.push_back(num);
			digit = 0;
			num = 0;
			tmp = "";
		}
	}
	return nums;
}
void print_vector(vector<int>v)
{
	for (auto ele : v)
	{
		cout << ele << " ";
	}
	cout << endl;
}
int count_digits(int num)
{
	if (num == 0)
		return 1;
	else
	{
		int digit = 0;
		while (num > 0)
		{
			num /= 10;
			digit++;
		}
		return digit;
	}
}
vector<int>crazy_vector()
{
	vector<int>v;
	for(int i = 999999; i >= 0;i--)
	{
		v.push_back(i);
	}
	return v;
}
vector<int>in_order_vector()
{
	vector<int>v;
	for(int i = 0; i <= 999999;i++)
	{
		v.push_back(i);
	}
	return v;
}
#endif