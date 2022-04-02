#ifndef _SOLUTION
#define _SOLUTION
#include <time.h>
#include <random>
#include <vector>
#include <iostream>
using namespace std;
struct Solution
{
    vector<int> random_v();
    void print_v(vector<int> v);
    int find_max(vector<int> v);
    int get_digit(int num);
    void count_sort(vector<int> &v);
    void radix_sort(vector<int> &v);
    int partition(vector<int> &, int, int);
    void quick_sort(vector<int> &, int, int);
};
vector<int> random_v()
{
    vector<int> v;
    int size = 100;
    srand(unsigned(time(NULL)));
    for (int i = 0; i < size; i++)
    {
        int num = rand() % size;
        v.push_back(num);
    }
    return v;
}
void print_v(vector<int> v)
{
    for (auto ele : v)
    {
        cout << ele << " ";
    }
    cout << endl;
}
int find_max(vector<int> v)
{
    int max = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > max)
            max = v[i];
    }
    return max;
}
int get_digit(int num)
{
    int digit = 1;
    while (num > 10)
    {
        digit++;
        num /= 10;
    }
    return digit;
}
void count_sort(vector<int> &v)
{
    int max = find_max(v);
    vector<int> acc(max + 1, 0);
    vector<int> res(v.size(), 0);
    for (int i = 0; i < v.size(); i++)
    {
        acc[v[i]]++;
    }
    for (int i = 1; i < acc.size(); i++)
    {
        acc[i] += acc[i - 1];
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        res[acc[v[i]] - 1] = v[i];
        acc[v[i]]--;
    }
    v = res;
}
// 1234
void radix_sort(vector<int> &v)
{
    vector<int> res(v.size(), 0);
    int digit = get_digit(find_max(v));
    for (int j = 0; j < digit; j++)
    {
        vector<int> digit_nums, acc(10, 0);
        for (int i = 0; i < v.size(); i++)
        {
            int temp = v[i] / pow(10, j);
            digit_nums.push_back(temp % 10);
        }
        for (int i = 0; i < digit_nums.size(); i++)
        {
            acc[digit_nums[i]]++;
        }
        for (int i = 1; i < acc.size(); i++)
        {
            acc[i] += acc[i - 1];
        }
        for (int i = v.size() - 1; i >= 0; i--)
        {
            int temp = v[i] / pow(10, j);
            int num = temp % 10;
            res[acc[num] - 1] = v[i];
            acc[num]--;
        }
        v = res;
    }
}
int partition(vector<int> &v, int l, int h)
{
    int i = h + 1, pivot = v[l];
    for (int j = h; j > l; j--)
    {
        if (v[j] >= pivot)
        {
            i--;
            swap(v[j], v[i]);
        }
    }
    swap(v[i - 1], v[l]);
    return (i - 1);
}
void quick_sort(vector<int> &v, int l, int r)
{
    if (l < r)
    {
        int p = partition(v, l, r);
        quick_sort(v, l, p - 1);
        quick_sort(v, p + 1, r);
    }
}
#endif