#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int cutRod(vector<int>, vector<int> &, int);
int cutRodAux(vector<int>, vector<int> &, int);
int BottomUpCutRod(vector<int>, vector<int> &, int);
void extend_cutRod(vector<int>, vector<int> &,vector<int>&, int);
void print_solution(vector<int>,vector<int>);
int max(int, int);
int main()
{
    vector<int> price = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int length;
    cin >> length;
    vector<int> ans(length + 1, 0),s(length+1,0);
    extend_cutRod(price,ans,s,length);
    print_solution(ans,s);
    return 0;
}
int max(int a, int b)
{
    return (a > b ? a : b);
}
int cutRodAux(vector<int> price, vector<int> &ans, int length)
{
    int temp;
    if (length == 0)
    {
        temp = 0;
    }
    else if (ans[length] >= 0)
    {
        return ans[length];
    }
    else
    {
        temp = INT_MIN;
        for (int i = 1; i <= length; i++)
        {
            temp = max(temp, price[i] + cutRod(price, ans, length - i));
        }
    }
    ans[length] = temp;
    return ans[length];
}
int cutRod(vector<int> price, vector<int> &ans, int length)
{
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i] = INT_MIN;
    }
    return cutRodAux(price, ans, length);
}
int BottomUpCutRod(vector<int> price, vector<int> &ans, int length)
{
    ans[0] = 0;
    for (int i = 1; i <= length; i++)
    {
        int temp = INT_MIN;
        for (int j = 1; j <= i; j++)
        {
            temp = max(temp, price[j] + ans[i - j]);
        }
        ans[i] = temp;
    }

    return ans[length];
}
void extend_cutRod(vector<int> price, vector<int> &ans,vector<int>&s, int length)
{
    ans[0] = 0;
    for (int i = 1; i <= length; i++)
    {
        int temp = INT_MIN;
        for (int j = 1; j <= i; j++)
        {
            if(temp<price[j]+ans[i-j])
            {
                temp  = price[j]+ans[i-j];
                s[i]=j;
            }
        }
        ans[i]=temp;
    }
}
void print_solution(vector<int>ans,vector<int>s)
{
    cout<<"$   ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<<"len ";
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}