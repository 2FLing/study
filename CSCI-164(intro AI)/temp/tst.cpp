#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    fstream file,new_file;
    file.open("a.txt", ios::in);
    if (file.is_open())
    {
        string temp, content = "";
        while (getline(file, temp, char(13)))
        {
            content += temp;
        }
    
    file.close();
    new_file.open("b.txt",ios::out);
    int index=0;
    while(index<content.size())
    {
        for(int i=0;i<50;i++)
        {
            new_file<<content[index++];
        }
        new_file<<endl;
    }
    new_file.close();
    }
    return 0;
}