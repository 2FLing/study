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
    void clear();

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
bool Pqueue::is_empty()
{
    return (v.size() == 0);
}
void Pqueue::clear()
{
    v.clear();
}
#endif // !_PQUEUE
