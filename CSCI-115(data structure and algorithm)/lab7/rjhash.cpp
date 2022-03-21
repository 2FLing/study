#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "hash_array.h"
using namespace std;

int main()
{
    ifstream file;
    string word, file_name = "RomeoAndJuliet.txt";
    int *update, *cost; //@HASHSIZE is from header file hash_array.h
    hash_array ha;
    file.open(file_name, ios::in);
    if (!file.is_open())
    {
        cout << "file does not exist!" << endl;
    }
    else
    {
        while (!file.eof())
        {
            file >> word;
            if (word != " ")
                ha.update(word);
        }
        file.close();
        cout << ha.size() << endl;
        cost = ha.get_costs();
        update = ha.get_updates();
        for (int i = 0; i < ha.size(); i++)
        {
            string comma = i == ha.size() - 1 ? "" : ", ";
            cout << cost[i] / update[i] << comma;
        }
    }
    return 0;
}
