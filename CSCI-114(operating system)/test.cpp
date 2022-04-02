#include <stdio.h>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;
void insert(vector<int> &);
bool remove(vector<int> &);
int main()
{
    vector<thread> trds;
    vector<vector<int>> v;
    vector<int>v1,v2,v3;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    for (int i = 0; i < 3; i++)
    {
        trds.push_back(thread(ref(insert), ref(v[i])));
    }
    trds[0].join();
    for (int i = 0; i < 3; i++)
    {
        if (remove(v[i]))
            cout << "removed queue " << i << endl;
        else
            cout << "nothing there."<<endl;
    }
    return 0;
}
void insert(vector<int> &v)
{
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
}
bool remove(vector<int> &v)
{
    for (int i = 0; i < 20; i++)
    {
        if (v.empty())
            return false;
        else
        {
            cout<<"removed "<<i<<endl;
            v.pop_back();
        }
    }
    return true;
}