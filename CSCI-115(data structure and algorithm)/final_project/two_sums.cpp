#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <chrono>
using namespace std;
mutex mtx;
condition_variable go;

int number_of_threads, resources, available;
void read_arguments(char**);
void request(vector<int>&, vector<int>&, int&, int);
void release(vector<int>&, vector<int>, int&, int);
void print_alloc(vector<int>);
void read_from_file(vector<int>&);
void banker(vector<int>&, vector<int>&, int&,vector<bool>&,vector<int>,int);

void read_arguments(char** args)
{
    args++;
    string temp = *args;
    number_of_threads = stoi(temp);
    args++;
    temp = *args;
    resources = stoi(temp);
    available = resources;
}
void request(vector<int>& allocation, vector<int>& need, int& available, int index)
{
    available--;
    need[index]--;
    allocation[index]++;
    print_alloc(allocation);
}
void release(vector<int>& allocation, vector<int> max, int& available, int index)
{
    available += max[index];
    allocation[index] = 0;
    print_alloc(allocation);
}
void print_alloc(vector<int> allocation)
{
    for (auto ele : allocation)
        cout << ele << " ";
    cout << endl;
}
void read_from_file(vector<int>& request)
{
    fstream file;
    file.open("requests.txt", ios::in);
    if (file.is_open())
    {
        string temp;
        while (getline(file, temp))
        {
            request.push_back(temp[2] - '0');
        }
        file.close();
    }
    else
    {
        cout << "file does not exist!" << endl;
    }
}

void banker(vector<int>& allocation,vector<int>& need, int& available,vector<bool>&ready,vector<int>max, int index)
{
    if (need[index] != 0)
    {
        unique_lock<std::mutex> mlock(mtx);
        if (need[index] > available)
            ready[index] = false;
        else
            ready[index] = true;

        while (!ready[index])
            go.wait(mlock);
        request(allocation, need, available, index);
        ready[index] = false;
        if (need[index] == 0)
            release(allocation, max, available, index);
        else
            banker(allocation, need, available, ready, max, index);
        for (int i = 0; i < ready.size(); i++)
        {
            ready[index] = true;
        }
        for (int i = 0; i < ready.size(); i++)
        {
            go.notify_one();
        }
    }
    

}
int main(int argv, char** args)
{
    vector<int> requests;
    vector<thread>thrds;
    int count = 0;
    read_arguments(args);
    read_from_file(requests);
    vector<int>allocation(number_of_threads, 0);
    vector<bool>ready(number_of_threads, false);
    vector<int>max, need, markers;
    for (int i = 0; i < number_of_threads; i++)
    {
        max.push_back(requests[i]);
        need.push_back(requests[i]);
        markers.push_back(i);
    }
    for (int i = 0; i < number_of_threads; i++)
    {
        thrds.push_back(thread(ref(banker), ref(allocation), ref(need), ref(available), ref(ready), ref(max), ref(i)));
    }
    for (int i = 0; i < thrds.size(); i++)
    {
        thrds[i].join();
    }
    return 0;
}