#include <iostream>
#include <vector>
using namespace std;
bool two_sum(vector<int>, int);
bool two_sum_evolve(vector<int>, int);
int main()
{
    vector<int> v = {1, 2, 3, 3, 6};
    cout << two_sum_evolve(v, 6);
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
bool two_sum_evolve(vector<int> v, int sum)
{
    int size = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > size)
            size = v[i];
    }
    vector<int> temp(size);
    for (int i = 0; i < v.size(); i++)
    {
        if (temp[sum - v[i]] != 0)
            return true;
        else
            temp[v[i]]++;
    }
    return false;
}