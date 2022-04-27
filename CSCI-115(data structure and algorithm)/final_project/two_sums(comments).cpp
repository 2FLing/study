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
// we are using a new array to store each number that we went through.
// the worst case will be we went through the whole given array, still could not find those two numbers
// therefore, for storing the whole given array, we need the range of the given array
// which will be [min,max].
// if the min > 0, then the range will be [0,max]
// if the max < 0, then the range will be [min,0]
// if min < 0 and max > 0 then the range will be [min,max]
bool two_sum_evolve(vector<int> v, int target)
{
    int size = 0, min = v[0], max = v[0];
    //find the max and min in the given array
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
        // because min < 0, size = -min + 1, 1 for the 0.                   
        size = 1 - min; 
    }
    else if (min > 0)
    {
        // 1 for the 0.
        size = max + 1; 
    }
    else
        // because min < 0, size = -min + max + 1, 1 for the 0.
        size = max - min + 1; 

    // temp is the array used for storing number that went through
    vector<int> temp(size); 

    for (int i = 0; i < v.size(); i++)
    {
        // what number we still need to make number + v[i] = target
        int still_need = target - v[i];
        // if number > max or number < min, it is absolutely not in the given array.
        if (still_need > max or still_need < min)
        {
            continue;
        }
        //otherwise check if it exists in those numbers already went through.
        //temp[still_need - min] == 0 means have not gone through yet
        //then mark the temp[v[i] - min] = 1 to record we went through v[i].
        //temp[still_need - min] == 1 means we went through the number we need
        //in other words, in the given array, it exists a number that number + v[i] = target.
        // therefore, return true.
        else if (temp[still_need - min] == 0)
            temp[v[i] - min]++;
        else
            return true;
    }
    return false;
}