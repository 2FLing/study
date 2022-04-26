#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <vector>
#include<algorithm>
#include<time.h>
#include<random>
using namespace std;
string hash_f(string);
string double_hash(string, int);
void read_file(string file_name, vector<string>& v);
void write_file(string file_name, vector<string>v);
void fix_data(string&);
unordered_map<string,int>ids;
int main()
{
    vector<string>team_id, player_id,player_in_file,team_in_file,team_short,player_name,team_name,t_in_p_file;
    unordered_map<string, string>pid, tid,stid,t_city;
    read_file("team_short.txt", team_short);
    read_file("player_in_file.txt", player_in_file);
    read_file("player_id.txt", player_id);
    read_file("team_id.txt", team_id);
    read_file("players.txt", player_name);
    read_file("teams.txt", team_name);
    read_file("team_in_file.txt", team_in_file);
    read_file("t_in_pfile.txt", t_in_p_file);
    for (int i = 0; i < player_name.size(); i++)
    {
        pid[player_name[i]] = player_id[i];
    }
    for (int i = 0; i < team_name.size(); i++)
    {
        tid[team_name[i]] = team_id[i];
    }
    for (int i = 0; i < team_short.size(); i++)
    {
        stid[team_short[i]] = team_id[i];
    }
    for (int i = 0; i < team_name.size(); i++)
    {
        t_city[team_name[i]] = team_short[i];
    }
    fstream pid_in_file, tid_in_pfile, tid_in_file,t_city_in_file;
    pid_in_file.open("pid_in_file.txt", ios::out);
    for (int i = 0; i < player_in_file.size(); i++)
    {
        pid_in_file << pid[player_in_file[i]] << endl;
    }
    pid_in_file.close();
    tid_in_pfile.open("tid_in_pfile.txt", ios::out);
    for (int i = 0; i < t_in_p_file.size(); i++)
    {
        tid_in_pfile << stid[t_in_p_file[i]] << endl;
    }
    tid_in_pfile.close();
    tid_in_file.open("tid_in_file.txt", ios::out);
    for (int i = 0; i < team_in_file.size(); i++)
    {
        tid_in_file << tid[team_in_file[i]] << endl;
    }
    pid_in_file.close();
    t_city_in_file.open("city.txt", ios::out);
    for (int i = 0; i < team_in_file.size(); i++)
    {
        t_city_in_file << t_city[team_in_file[i]] << endl;
    }
    t_city_in_file.close();
    return 0;
}
string double_hash(string name, int num)
{
    return to_string(((num * stoi(hash_f(name)))) % 701);
}
string hash_f(string name)
{
    srand((unsigned)time(NULL));
    int sum = rand() % 9999+1000;
    return to_string(sum);
}
void read_file(string file_name, vector<string>& v)
{
    string temp;
    fstream file;
    file.open(file_name, ios::in);
    if (file.is_open())
    {
        while (getline(file, temp))
        {
            v.push_back(temp);
        }
        file.close();
    }
}
void fix_data(string& data)
{
    string new_data = "";
    int count = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == ' ')
        {
            count++;
            if (count != 1)
                new_data += '\t';
            else
                new_data += data[i];
        }
        else
        {
            new_data += data[i];
        }
    }
    data = new_data;
}