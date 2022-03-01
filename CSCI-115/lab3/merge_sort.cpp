#include<time.h>
#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&, int, int, int);
void merge_sort(vector<int>&, int, int);
void reversed_vector(vector<int>&,int);
void half_reversed_vector(vector<int>&, int);
void in_ordered_vector(vector<int>&, int);
void print_vector(vector<int>);
int main()
{
	vector<int> reversed_v,half_reversed_v,in_ordered_v;
	float start_re, end_re, start_hre,end_hre,start_io,end_io;
	reversed_vector(reversed_v,50000);
	half_reversed_vector(half_reversed_v, 50000);
	in_ordered_vector(in_ordered_v, 50000);
	start_re = clock();
	merge_sort(reversed_v,0, reversed_v.size());
	end_re = clock();
	start_hre = clock();
	merge_sort(half_reversed_v, 0, half_reversed_v.size());
	end_hre = clock();
	start_io = clock();
	merge_sort(in_ordered_v, 0, in_ordered_v.size());
	end_io = clock();
	cout << "It takes merge sort " << (end_re - start_re) / CLOCKS_PER_SEC << "s to finish sorting a reversed vector." << endl;
	cout << "It takes merge sort " << (end_hre - start_hre) / CLOCKS_PER_SEC << "s to finish sorting a half reversed vector." << endl;
	cout << "It takes merge sort " << (end_io - start_io) / CLOCKS_PER_SEC << "s to finish sorting a in ordered vector." << endl;
	return 0;
}

void merge(vector<int>&v, int l, int m, int r)
{
	if (v.size() > 1)
	{
		vector<int>lv;
		vector<int>rv;
		int len1 = m - l;
		int len2 = r - m;
		for (int i = 0; i < len1; i++)
		{
			lv.push_back(v[i+l]);
		}
		for (int i = 0; i < len2; i++)
		{
			rv.push_back(v[i+m]);
		}
		lv.push_back(INT_MAX);
		rv.push_back(INT_MAX);
		int j = 0, k = 0, pos = l;
		for (int i = l; i < r; i++)
		{
			if (lv[j] <= rv[k])
				v[i] = lv[j++];
			else
				v[i] = rv[k++];
		}
	}

}

void merge_sort(vector<int>&v, int l, int r)
{
	if (r-l>1)
	{
		int middle = (l + r) / 2;
		merge_sort(v, l, middle);
		merge_sort(v, middle, r);
		merge(v, l, middle, r);
	}
	
}

void reversed_vector(vector<int>& v,int len)
{
	for (int i = len; i >= 0; i--)
		v.push_back(i);
}

void half_reversed_vector(vector<int>& v, int len)
{
	for (int i = 0; i < len / 2; i++)
	{
		v.push_back(i);
	}
	for (int i = len / 2; i >= 0; i--)
	{
		v.push_back(i);
	}
}

void print_vector(vector<int>v)
{
	for (auto ele : v)
		cout << ele << " ";
	cout << endl;
}
void in_ordered_vector(vector<int>& v, int len)
{
	for (int i = 0; i <= len; i++)
		v.push_back(i);
}