#include <iostream>
#include "red_black_tree.h"
using namespace std;
int main()
{
    int step =0;
    string str = "12 3 6 9";
    str.push_back(' ');
    while(str.find(' ')!=0)
    {
        cout<<str<<endl;
        str = str.substr(str.find(' '),str.size()-str.find(' '));
    }
    return 0;
}