#include <iostream>
#include <time.h>
#include <random>
#include "Sorts.h"
using namespace std;
void print_v(vector<int>);
vector<int> in_order(int);
vector<int> reversed(int);
vector<int> random(int);
bool is_sorted(vector<int>);
int main()
{
    Sorts sort;
    float start, end, time;
    vector<int> v = random(10000);
    start = clock();
    sort.bubble_sort(v);
    end = clock();
    time = (end - start) / CLOCKS_PER_SEC;
    cout<<is_sorted(v)<<endl;
    cout<<time<<"s"<<endl;
    return 0;
}

vector<int> in_order(int size)
{
    vector<int> v;
    for (int i = 0; i < size; i++)
        v.push_back(i);
    return v;
}
vector<int> reversed(int size)
{
    vector<int> v;
    for (int i = size - 1; i >= 0; i--)
        v.push_back(i);
    return v;
}
vector<int> random(int size)
{
    vector<int> v;
    srand((unsigned)time(NULL));
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
bool is_sorted(vector<int> v)
{
    bool sorted = true;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i + 1] < v[i])
            sorted = false;
    }
    return sorted;
}