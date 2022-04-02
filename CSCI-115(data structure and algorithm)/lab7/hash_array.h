#ifndef _HASHARRAY
#define _HASHARRAY
#include <string>
#include <iostream>
using namespace std;
const int HASHSIZE = 4001;
class hash_array
{
public:
    hash_array();
    int size();
    void update(string);
    int hash_func(string);
    int probes();
    int *get_costs();
    int *get_updates();

private:
    string hash_table[HASHSIZE];
    int hash_a[HASHSIZE];
    int len_of_array = 0;
    int number_array_access = 0;
    int updates[HASHSIZE];
    int cost[HASHSIZE];
};
hash_array::hash_array()
{
    for (int i = 0; i < HASHSIZE; i++)
    {
        hash_a[i] = 0;
        updates[i] = 0;
        cost[i] = 0;
        hash_table[i] = "Nil";
    }
}
int hash_array::hash_func(string word)
{
    int sum = 0;
    for (int ele : word)
    {
        sum += ele;
    }
    return (sum % HASHSIZE);
}
int hash_array::size()
{
    return len_of_array;
}
void hash_array::update(string word)
{
    int i = 0, key = hash_func(word);
    do
    {
        i++;
        if (hash_table[key] == word)
        {
            i = HASHSIZE;
            break;
        }
        if (hash_table[key] == "Nil")
        {
            hash_table[key] = word;
            break;
        }
        else
        {
            if (key == HASHSIZE)
                key = 0;
            else
                key++;
        }
    } while (i < HASHSIZE);
    if (i != HASHSIZE)
    {
        cost[len_of_array] = i;
        updates[len_of_array]++;
        number_array_access = i;
        len_of_array++;
        hash_a[key]++;
    }
}
int hash_array::probes()
{
    return number_array_access;
}
int *hash_array::get_costs()
{
    return cost;
}
int *hash_array::get_updates()
{
    return updates;
}
#endif