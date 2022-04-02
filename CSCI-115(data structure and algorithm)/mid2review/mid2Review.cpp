#include"Solution.h"
using namespace std;
int main()
{
    vector<int>v=random_v();
    quick_sort(v,0,v.size()-1);
    print_v(v);
    return 0;
}