#ifndef _QUEUE
#define QUEUE
#include <vector>
using namespace std;
class Queue // FIFO
{
public:
    Queue();
    Queue(int);
    void insert(int);
    int pop();
    bool exist(int);
    bool is_empty();

private:
    vector<int> v;
};
Queue::Queue()
{

}
Queue::Queue(int n)
{
    v.push_back(n);
}
void Queue::insert(int n)
{
    v.push_back(n);
}
int Queue::pop()
{
    if (is_empty())
    {
        cout<<"Nothing pop out because the queue is empty."<<endl;
        return -1;
    }
    else
    {
        int temp = v[0];
        for (int i = 0; i < v.size() - 1; i++)
        {
            v[i] = v[i + 1];
        }
        v.pop_back();
        return temp;
    }
}
bool Queue::exist(int n)
{
    bool res = false;
    for (auto ele : v)
    {
        if (ele == n)
            res = true;
    }
    return res;
}
bool Queue::is_empty()
{
    return (v.size() == 0);
}

#endif
