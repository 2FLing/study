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
void release(vector<int>&, vector<bool>&,vector<int>, int&, int);
void print_alloc(vector<int>);
void read_from_file(vector<int>&);
void banker(vector<int>&, vector<int>&, int&, vector<bool>&, vector<bool>&, vector<int>, int);
bool notify_next(vector<bool>, vector<bool>&,int);
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
void release(vector<int>& allocation, vector<bool>&finish, vector<int> max, int& available, int index)
{
    finish[index] = true;
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
bool notify_next(vector<bool>finish, vector<bool>& ready, int index)
{
    bool successfully = false;
    int temp = index + 1;
    for (auto ele : finish)
    {
        if (!ele)
            successfully = true;
    }
    if (!successfully)
        return successfully;
    while (finish[temp % number_of_threads])
        temp++;
    ready[temp % number_of_threads] = true;
    return successfully;
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
            temp = temp.substr(2, temp.size() - 2);
            request.push_back(stoi(temp));
        }
        file.close();
    }
    else
    {
        cout << "file does not exist!" << endl;
    }
}

void banker(vector<int>& allocation, vector<int>& need, int& available, vector<bool>& ready, vector<bool>&finish, vector<int>max, int index)
{
    unique_lock<std::mutex> mlock(mtx);
    while (need[index] != 0)
    {
        while (need[index] > available)
        {
            notify_next(finish, ready, index);
            go.notify_one();
            go.wait(mlock);
        }
        request(allocation, need, available, index);
        if (need[index] == 0)
        {
            release(allocation, finish, max, available, index);
            if(!notify_next(finish, ready, index))
                break;
            go.notify_one();
            break;
        }
        ready[index] = false;
        notify_next(finish, ready, index);
        go.notify_one();
        while (!ready[index])
            go.wait(mlock);
    }


}
int main(int argv, char** args)
{
    vector<int> requests;
    vector<thread>thrds;
    int count = 0;
    read_arguments(args);
    read_from_file(requests);
    for (auto ele : requests)
    {
        if (resources < ele)
        {
            cout << "The require unit is larger than the resourse." << endl;
            exit(1);
        }
    }
    int temp = 0;
    for (int i = 0; i < requests.size(); i += number_of_threads)
    {
        vector<int>max, need;
        vector<int>allocation(number_of_threads, 0);
        vector<bool>ready(number_of_threads, false);
        vector<bool>finish(number_of_threads, false);
        print_alloc(allocation);
        for (int j = 0; j < number_of_threads; j++)
        {
            max.push_back(requests[j + i]);
            need.push_back(requests[j + i]);
        }
        for (int j = 0; j < number_of_threads; j++)
        {
            thrds.push_back(thread(ref(banker), ref(allocation), ref(need), ref(available), ref(ready),ref(finish), ref(max), j));
        }
        for (int j = 0; j < number_of_threads; j++)
        {
            thrds[j].join();
        }
        thrds.clear();
    }
    return 0;
}