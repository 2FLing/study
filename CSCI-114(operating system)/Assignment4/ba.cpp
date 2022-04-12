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
bool other_running = false;
int number_of_threads, resources, available;
void read_arguments(char**);
void request(vector<int>&, vector<int>&, vector<bool>&, int&, bool&, int);
void release(vector<int>&, vector<int>&, vector<bool>&, int&, int);
void print_alloc(vector<int>);
void read_from_file(vector<int>&);
void restore(vector<int>&, vector<bool>&);
void read_arguments(char** args)
{
    args++;
    string temp = *args;
    number_of_threads = stoi(temp);
    args++;
    temp = *args;
    resources = stoi(temp);

}
void request(vector<int>& allocation, vector<int>& max, vector<bool>& finish, int& available, bool& other_running, int index)
{
    unique_lock<mutex> m_lock(mtx);
    while (!finish[index])
    {
        if (!other_running)
        {

            if (available > 1)
            {
                other_running = true;
                allocation[index]++;
                if (allocation[index] == max[index])
                    release(allocation, max, finish, available, index);
                else
                {
                    available--;
                    print_alloc(allocation);
                }
                other_running = false;
                go.notify_one();
            }
            else
            {
                if (allocation[index] + available == max[index])
                {
                    other_running = true;
                    allocation[index]++;
                    available--;
                    release(allocation, max, finish, available, index);
                    other_running = false;
                    go.notify_one();
                }
                else
                {
                    go.wait(m_lock);
                }
            }
        }
        else
        {
            go.wait(m_lock);
        }
    }
}
void release(vector<int>& allocation, vector<int>& max, vector<bool>& finish, int& available, int index)
{
    print_alloc(allocation);
    available += max[index];
    finish[index] = true;
    allocation[index] = 0;
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
void restore(vector<int>& allocation, vector<bool>& finish)
{
    for (int i = 0; i < allocation.size(); i++)
    {
        allocation[i] = 0;
        finish[i] = false;
    }
}
int main(int argv, char** args)
{
    vector<int> requests;
    int index = 0;
    read_arguments(args);
    read_from_file(requests);
    vector<thread> thrd;
    vector<int> allocation(number_of_threads, 0), max(number_of_threads, 0);
    vector<bool> finish(number_of_threads, false);
    available = resources;
    for (int i = 0; i < requests.size(); i++)
    {
        max[index++] = requests[i];
        if ((i + 1) % number_of_threads == 0)
        {
            for (int j = 0; j < number_of_threads; j++)
                thrd.push_back(thread(ref(request), ref(allocation), ref(max), ref(finish), ref(available), ref(other_running), j));
            for (int k = 0; k < thrd.size(); k++)
                thrd[k].join();
            thrd.clear();
            restore(allocation, finish);
            index = 0;
        }
    }
    return 0;
}