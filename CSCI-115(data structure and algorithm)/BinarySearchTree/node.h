#ifndef _NODE_H
#define _NODE_H
#include <stdio.h>
using namespace std;
class Node
{
public:
    Node(int);
    Node(int, Node *, Node *);
    void set_val(int);
    int get_val();
    Node *get_left();
    Node *get_right();
    void set_left(Node *);
    void set_right(Node *);
    Node *get_parent();
    void set_parent(Node *);
private:
    int val;
    Node *left;
    Node *right;
    Node *parent;
};
Node::Node(int num)
{
    val = num;
    left = NULL;
    right = NULL;
}
Node::Node(int num, Node *l, Node *r)
{
    val = num;
    left = l;
    right = r;
    if (l)
        l->set_parent(this);
    if (r)
        r->set_parent(this);
}
void Node::set_val(int num)
{
    val = num;
}
int Node::get_val()
{
    return val;
}
Node *Node::get_left()
{
    return left;
}
Node *Node::get_right()
{
    return right;
}
void Node::set_left(Node *node)
{
    left = node;
    if (node)
        node->set_parent(this);
}
void Node::set_right(Node *node)
{
    right = node;
    if (node)
        node->set_parent(this);
}
void Node::set_parent(Node *node)
{
    parent = node;
}
Node *Node::get_parent()
{
    return parent;
}
#endif