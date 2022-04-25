#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <vector>
using namespace std;
string hash_f(string);
string double_hash(string, int);
unordered_map<string, int> player_id;
unordered_map<string,int>teams;
int main()
{
    fstream file;
    unordered_map<string,int>t_name;
    vector<string>t_f_name;
    file.open("team.txt",ios::in);
    if(file.is_open())
    {
        string temp;
        while(getline(file,temp))
        {
            if(teams[temp]==0)
            {
                t_f_name.push_back(temp);
                teams[temp]++;
            }
        }
        file.close();
    }
    fstream tname;
    tname.open("new_team.txt",ios::out);
    for(int i=0;i<t_f_name.size();i++)
    {
        tname<<t_f_name[i]<<endl;
    }
    tname.close();
    return 0;
}
string double_hash(string name, int num)
{
    return to_string(5 - num * stoi(hash_f(name)) % 5);
}
string hash_f(string name)
{
    int sum = 0;
    for (int i = 0; i < name.size(); i++)
    {
        sum += name[i];
    }
    return to_string(sum % 4001);
}