#include<stdio.h>
#include<iostream>
#include<thread>
#include<vector>
using namespace std;
void accumulate_range(int&,int,int);
void print_vector(vector<int>);
int sum_vector(vector<int>);
int main()
{
    const int number_of_threads = 1000;
    const int number_of_elements = 1000;
    const int step = number_of_elements / number_of_threads;
    int sum;
    vector<int>partial_sums(number_of_threads);
    vector<thread>trds;
    for (int i = 0; i < number_of_threads; i++)
    {
        int start_point = i * step;
        trds.push_back(thread(accumulate_range, ref(partial_sums[i]), start_point, start_point+step));
    }
    for (thread& t : trds)
    {
        if (t.joinable())
            t.join();
    }
    print_vector(partial_sums);
    cout << "finally!" << endl;
    sum = sum_vector(partial_sums);
    cout << sum << endl;
    return 0;
}
void accumulate_range(int& res, int s, int e)
{
    if (s < e)
    {
        res = 0;
        for (int i = s; i < e; i++)
        {
            res += i;
        }
    }
}
void print_vector(vector<int>v)
{
    for (auto ele : v)
    {
        cout << ele<<" ";
    }
    cout << endl;
}
int sum_vector(vector<int>v)
{
    int sum=0;
    for(auto ele:v)
    {
        sum += ele;
    }
    return sum;
}