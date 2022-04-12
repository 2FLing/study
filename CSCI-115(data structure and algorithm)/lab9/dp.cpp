#include <stdio.h>
#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;
void m_stoi(string, vector<int>&);
void matrix_chain_order(vector<int>, vector<vector<int>>&, vector<vector<int>>&, int);
void print_opt_parens(vector<vector<int>>, int, int, string);

int main()
{
    vector<int> p;
    string nums, choice;
    while (choice != "n")
    {
        p.clear();
        cout << "Enter a list of numbers(seperate by space):";
        getline(cin, nums);
        m_stoi(nums, p);
        vector<int> temp(p.size(), 0);
        vector<vector<int>> m(p.size()+1,vector<int>(p.size()+1)), s(p.size()+1, vector<int>(p.size()+1));
        matrix_chain_order(p, m, s, p.size());
        cout << "continue?(\'n\' for quit):";
        getline(cin, choice);
    }
    return 0;
}

void print_opt_parens(vector<vector<int>>s, int i, int j, string name)
{
    if (i == j)
    {
        cout << name << i;
    }
    else
    {
        cout << "(";
        print_opt_parens(s, i, s[i][j], name);
        print_opt_parens(s, s[i][j] + 1, j, name);
        cout << ")";
    }
}
void m_stoi(string str, vector<int>& v)
{
    str.push_back(' ');
    string temp = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            v.push_back(stoi(temp));
            temp = "";
        }
        else
        {
            temp.push_back(str[i]);
        }
    }
}
void matrix_chain_order(vector<int> p, vector<vector<int>>& m, vector<vector<int>>& s, int length)
{
    for (int i = 0; i < length; i++)
    {
        m[i][i] = 0;
    }
    for (int l = 2; l < length; l++)
    {
        for (int i = 1; i < length - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k+1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    string name = "A";
    cout << "Optimal Parenthesization is :";
    print_opt_parens(s, 1, p.size() - 1, name);
    cout << endl;
    cout << "Optimal Cost is : " << m[1][length - 1] << endl;
}
// 10 20 30 40 30
// 1 2  2 3  3 4  4 5  5 6
// 1 3  2 4  3  5 4 6 
//  1 2 3 4 5 6
// 6
// 5
// 4
// 3
// 2
// 1