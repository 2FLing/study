#include <iostream>
#include <vector>
#include<random>
#include<time.h>
using namespace std;
bool two_sum(vector<int>, int);
bool two_sum_evolve(vector<int>, int);
vector<int>make_v(int size);
int main()
{
    vector<int> v = make_v(1000000);
    float end, start;
    v.push_back(-1);
    v.push_back(3999999);
    start = clock();
    cout << two_sum_evolve(v, 3999998)<<endl;
    end = clock();
    cout << (end - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}

bool two_sum(vector<int> v, int sum)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] + v[j] == sum)
            {
                return true;
            }
        }
    }
    return false;
}
bool two_sum_evolve(vector<int> v, int target)
{
    int size = 0, min = v[0], max = v[0];
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            if (v[i] > max)
                max = v[i];
            if (v[i + 1] < min)
                min = v[i + 1];
        }
        else
        {
            if (v[i + 1] > max)
                max = v[i + 1];
            if (v[i] < min)
                min = v[i];
        }
    }
    if (max < 0)
    {
        size = 1 - min;
    }
    else if (min > 0)
    {
        size = max + 1;
    }
    else
        size = max - min + 1;

    vector<int> temp(size);

    for (int i = 0; i < v.size(); i++)
    {
        int still_need = target - v[i];
        if (still_need > max || still_need < min)
        {
            continue;
        }
        else if (temp[still_need - min] == 0)
            temp[v[i] - min]++;
        else
            return true;
    }
    return false;
}
vector<int>make_v(int size)
{
    vector<int>v;
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; i++)
    {
        int t = rand() % size-size;
        v.push_back(t);
    }
    return v;
}