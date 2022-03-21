#ifndef _QUEUE
#define QUEUE
#include "Node.h"
#include <vector>
using namespace std;
class Queue // FIFO
{
public:
    Queue(Node *);
    void insert(Node *);
    Node *pop();
    bool exist(Node *);
    bool is_empty();

private:
    vector<Node *> v;
};
Queue::Queue(Node *node)
{
    v.push_back(node);
}
void Queue::insert(Node *node)
{
    v.push_back(node);
}
Node *Queue::pop()
{
    if (is_empty())
    {
        return NULL;
    }
    else
    {
        Node *temp = v[0];
        for (int i = 0; i < v.size() - 1; i++)
        {
            v[i] = v[i + 1];
        }
        v.pop_back();
        return temp;
    }
}
bool Queue::exist(Node *node)
{
    bool res = false;
    for (auto ele : v)
    {
        if (ele->get_val() == node->get_val())
            res = true;
    }
    return res;
}
bool Queue::is_empty()
{
    return (v.size() == 0);
}

#endif