#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3};
    v.erase(v.begin(),v.begin()+1);
    for (auto ele : v)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}