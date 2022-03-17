#ifndef _QUICK_SORT
#define _QUICK_SORT
#include<vector>
#include<stdio.h>
#include<string>
#include<iostream>
#include<time.h>
#include<random>
using namespace std;
int partition(vector<int>&,int,int);
void quick_sort(vector<int>&,int,int);
int random_partition(vector<int>&,int,int);
void random_quick_sort(vector<int>&,int,int);
int median_partition(vector<int>&,int,int);
void median_quick_sort(vector<int>&,int,int);
int pick_median(int,int,int);
vector<int> create_vector();
void print_vector(vector<int>);

int random_partition(vector<int>&v,int low,int high)
{
    srand(time(NULL));
    int i=rand()%(high-low)+low;
    swap(v[i],v[low]);
    return partition(v,low,high);
}
void random_quick_sort(vector<int>&v,int low,int high)
{
    if(low<high)
    {
        int p = random_partition(v,low,high);
        random_quick_sort(v,low,p-1);
        random_quick_sort(v,p+1,high);
    }
}
int median_partition(vector<int>&v,int low,int high)
{
    int middle=(low+high)/2, median= pick_median(v[0],v[middle],v[high]);
    if(v[high]==median)
        swap(v[high],v[low]);
    else if(v[middle]==median)
        swap(v[middle],v[low]);
    return partition(v,low,high);
}
void median_quick_sort(vector<int>&v,int low,int high)
{
    if(low<high)
    {
        int p = median_partition(v,low,high);
        median_quick_sort(v,low,p-1);
        median_quick_sort(v,p+1,high);
    }
}
int partition(vector<int>&v,int low,int high)
{
    int pivot=v[low];
    int i=high+1;
    for(int j=high;j>low;j--)
    {
        if(v[j]>=pivot)
        {
            i--;
            swap(v[i],v[j]);
        }
    }
    swap(v[i-1],v[low]);
    return i-1;
}
void quick_sort(vector<int>&v,int low,int high)
{
    int q;
    if(low<high)
    {
        q=partition(v,low,high);
        quick_sort(v,low,q-1);
        quick_sort(v,q+1,high);
    }
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
    for(auto ele:v)
        cout<<ele<<" ";
    cout<<endl;
}
int pick_median(int a,int b,int c)
{
    int avg=(a+b+c)/3;
    pair<int,int> p1(a,avg),p2(b,avg),p3(c,avg);
    int p1_diff=abs(p1.first-p1.second),p2_diff=abs(p2.first-p2.second),p3_diff=abs(p3.first-p3.second);
    int min_diff=min(p1_diff,min(p2_diff,p3_diff));
    if(p1_diff==min_diff)
        return a;
    else if(p2_diff == min_diff)
        return b;
    else
        return c;
}
#endif

