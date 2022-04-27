#include <iostream>
#include <vector>
using namespace std;
bool two_sum(vector<int>, int);
bool two_sum_evolve(vector<int>, int);
int main()
{
    vector<int> v = {1, -2, 3, 3, 6};
    cout << two_sum_evolve(v, 1);
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
        if (still_need > max or still_need < min)
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