// I executed my program on cygwin terminal
// Before execution, you have to convert the cpp file
// to exe by using g++ CSci114_P4.cpp -o anyname
// then you will see a anyname.exe in the same folder
// when you run the exe program you will need the
// number of threads and the number of the shrared object. For example, if
// number of thread is 5, and mthe number of the shrared object is 8
// for running the exe file, you have to put
// ./(the name you defined for the .exe file) 5 8
// Then you should see the content of the allocation.

// Sometimes Cygwin will stuck when printing the allocation,
// but the program is actually good. Therefore, I made a txt file
// to store the allocation, if the program stuck when printing the
// allocation, you can go to the folder where the cpp file stored,
// then you should see the result.txt file, you can check the file for the result.

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
using namespace std;
mutex mtx;
condition_variable go;

int number_of_threads, resources, available;
void read_arguments(char **);
void request(vector<int> &, int &, int &, int);
void release(vector<vector<int>> &, vector<int> &, vector<bool> &, int &, int);
void print_alloc(vector<int>);
void read_from_file(vector<vector<int>> &);
void banker(vector<vector<int>> &, vector<int> &, int &, vector<bool> &, vector<bool> &, int);
bool notify_next(vector<bool>, vector<bool> &, int);
void write_file(vector<int>);
// write the content of an array into a txt file
void write_file(vector<int> v)
{
    fstream file;
    file.open("result.txt", ios::app);
    for (int i = 0; i < v.size(); i++)
    {
        file << to_string(v[i]) << " ";
    }
    file << endl;
    file.close();
}
void read_arguments(char **args)
{
    args++;
    string temp = *args;
    number_of_threads = stoi(temp);
    args++;
    temp = *args;
    resources = stoi(temp);
    available = resources;
}
void request(vector<int> &allocation, int &need, int &available, int index)
{
    available--;
    need--;
    allocation[index]++;
    print_alloc(allocation);
}
void release(vector<vector<int>> &request, vector<int> &allocation, vector<bool> &finish, int &available, int index)
{
    available += request[index][0];
    allocation[index] = 0;
    print_alloc(allocation);
    if (request[index].size() == 1)
        finish[index] = true;
    else
    {
        request[index].erase(request[index].begin(), request[index].begin() + 1);
    }
}
void print_alloc(vector<int> allocation)
{
    write_file(allocation);
    for (auto ele : allocation)
        cout << ele << " ";
    cout << endl;
}
bool notify_next(vector<bool> finish, vector<bool> &ready, int index)
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
    // if the thread is finished already then skip it
    while (finish[temp % number_of_threads])
        temp++;
    // make next thread to be ready to run
    ready[temp % number_of_threads] = true;
    return successfully;
}
void read_from_file(vector<vector<int>> &request)
{
    fstream file, result;
    file.open("requests.txt", ios::in);
    if (file.is_open())
    {
        string temp;
        int index;
        while (getline(file, temp))
        {
            if (temp.size() < 3)
                break;
            index = stoi(temp.substr(0, temp.find(" ")));
            if (index > number_of_threads)
            {
                cout << "The input number of thread is smaller than the current number of thread." << endl;
                exit(1);
            }
            temp = temp.substr(temp.find(" "));
            request[index - 1].push_back(stoi(temp));
        }
        file.close();
    }
    else
    {
        cout << "file does not exist!" << endl;
    }
}

void banker(vector<vector<int>> &requests, vector<int> &allocation, int &available, vector<bool> &ready, vector<bool> &finish, int index)
{
    unique_lock<std::mutex> mlock(mtx);
    int need = requests[index][0] - allocation[index];
    // check if the thread needs 0 unit first, if it does then not neccessary to execute rest.
    if (need == 0)
        finish[index] = true;
    while (need != 0)
    {
        // if the current thread needs more than available, put it in wait list.
        while (need > available)
        {
            notify_next(finish, ready, index);
            ready[index] = false;
            go.notify_one();
            go.wait(mlock);
        }
        request(allocation, need, available, index);
        if (need == 0)
        {
            release(requests, allocation, finish, available, index);
            // if there is still request for the current thread, then calculate its next need.
            if (!finish[index])
                need = requests[index][0] - allocation[index];
            ready[index] = false;
            // if notify next fail, that means all threads got satisfied, so break the loop.
            if (!notify_next(finish, ready, index))
                break;
            // if there is still thread not be satisfied yet then notify next to be ready.
            go.notify_one();
            // if the current thread is finished then break the loop.
            if (finish[index])
                break;
            // if the current thread is not finished yet then it has to wait for the next turn.
            while (!ready[index])
                go.wait(mlock);
        }
        else
        {
            ready[index] = false;
            notify_next(finish, ready, index);
            go.notify_one();
            while (!ready[index])
                go.wait(mlock);
        }
    }
}
int main(int argv, char **args)
{
    vector<vector<int>> requests;
    vector<thread> thrds;
    fstream file;
    file.open("result.txt", ios::out);
    file.close();
    read_arguments(args);
    vector<int> allocation(number_of_threads, 0);
    vector<bool> ready(number_of_threads, false);
    vector<bool> finish(number_of_threads, false);
    requests = vector<vector<int>>(number_of_threads);
    read_from_file(requests);
    for (auto ele : requests)
    {
        for (int i = 0; i < ele.size(); i++)
        {
            if (ele[i] > resources)
            {
                cout << "The require unit is larger than the resourse." << endl;
                exit(1);
            }
        }
    }
    for (int i = 0; i < requests.size(); i++)
    {
        thrds.push_back(thread(ref(banker), ref(requests), ref(allocation), ref(available), ref(ready), ref(finish), i));
    }
    for (int i = 0; i < requests.size(); i++)
    {
        thrds[i].join();
    }
    return 0;
}