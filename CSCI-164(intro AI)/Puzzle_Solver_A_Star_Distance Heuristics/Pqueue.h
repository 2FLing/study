#ifndef _PQUEUE
#define _PQUEUE
#include <vector>
#include "Node.h"
using namespace std;
class Pqueue
{
public:
    Pqueue(Node *node);
    Node *pop();
    void insert(Node *node);
    bool is_empty();
    int exist(Node *);// check if the node is already in the pqueue, if it does then return its index otherwise return -1.

private:
    vector<Node *> v;
};

Pqueue::Pqueue(Node *node)
{
    v.push_back(node);
}
Node *Pqueue::pop()
{
    if (v.size() == 0)
        return NULL;
    else
    {
        Node *temp = v[v.size() - 1];
        v.pop_back();
        return temp;
    }
}
void Pqueue::insert(Node *node)
{
    if (v.size() == 0)
    {
        v.push_back(node);
    }
    else
    {
        int index = exist(node);
        if (index != -1)
        {
            if (node->get_priority() < v[index]->get_priority())
            {
                v[index] = node;
            }
        }
        else
        {
            v.push_back(v[0]);
            int i = 0;
            while (i < v.size())
            {
                if (node->get_priority() <= v[i]->get_priority())
                    i++;
                else
                {
                    break;
                }
            }
            if (i == v.size())
            {
                v[v.size() - 1] = node;
            }
            else
            {
                for (int j = v.size() - 1; j > i; j--)
                {
                    v[j] = v[j - 1];
                }
                v[i] = node;
            }
        }
    }
}
bool Pqueue::is_empty()
{
    return (v.size() == 0);
}
int Pqueue::exist(Node *node)
{
    int index = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == node)
            index = i;
    }
    return index;
}
#endif // !_PQUEUE
