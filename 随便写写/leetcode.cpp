#include <string>
#include <math.h>
#include <iostream>
#include <climits>
using namespace std;
int myAtoi(string);
int main()
{
    cout << myAtoi("4193 with word");
    return 0;
}
int myAtoi(string s)
{
    int sign = 1, j = 0;
    long res = 0;
    while (isspace(s[j]))
    {
        j++;
    }
    if (s[j] == '-')
    {
        sign = -1;
        j++;
    }
    for (int i = j; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            int digit = s[i] - '0';
            if (res > INTMAX_MAX / 10 || res == INT_MAX / 10 && digit > INTMAX_MAX % 10)
                return sign == -1?INT_MIN:INT_MAX;
            res = res * 10 + digit;
        }
        else
            break;
    }
    return sign*res;
}