#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
void selection_sort(vector<int>&);
void reversed_vector(vector<int>&,int);
void half_reversed_vector(vector<int>&, int);
void in_ordered_vector(vector<int>&, int);
void print_vector(vector<int>);
int main()
{
	vector<int> reversed_v, half_reversed_v, in_ordered_v;
	float start_re, end_re, start_hre, end_hre, start_io, end_io;
	reversed_vector(reversed_v, 50000);
	half_reversed_vector(half_reversed_v, 50000);
	in_ordered_vector(in_ordered_v, 50000);
	start_re = clock();
	selection_sort(reversed_v);
	end_re = clock();
	start_hre = clock();
	selection_sort(half_reversed_v);
	end_hre = clock();
	start_io = clock();
	selection_sort(in_ordered_v);
	end_io = clock();
	cout << "It takes selection sort " << (end_re - start_re) / CLOCKS_PER_SEC << "s to finish sorting a reversed vector." << endl;
	cout << "It takes selection sort " << (end_hre - start_hre) / CLOCKS_PER_SEC << "s to finish sorting a half reversed vector." << endl;
	cout << "It takes selection sort " << (end_io - start_io) / CLOCKS_PER_SEC << "s to finish sorting a in ordered vector." << endl;
	return 0;
}

void selection_sort(vector<int>& v)
{
	if (v.size() > 1)
	{
		int min_index = 0, Start = 0, min = v[0];
		while (Start < v.size() - 1)
		{
			for (int i =Start; i < v.size(); i++)
			{
				if (v[i] < min)
				{
					min = v[i];
					min_index = i;
				}
			}
			swap(v[min_index], v[Start]);
			Start++;
			min_index = Start;
			min = v[Start];
		}
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