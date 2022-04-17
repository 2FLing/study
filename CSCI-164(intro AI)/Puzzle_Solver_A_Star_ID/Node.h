#ifndef _NODE
#define _NODE
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
class Node
{
public:
    Node(string);
    Node(string, int prt);
    Node(string num, Node *node, int prt);
    Node(string num, int, int prt);
    ~Node();
    string get_val();
    void set_val(string);
    void set_next(Node *);
    void set_parent(Node *);
    Node *get_parent();
    Node *get_next_node();
    void set_depth(int);
    int get_depth();
    void set_priority(int);
    int get_priority();

private:
    string nums;
    Node *next_node;
    Node *parent;
    int priority;
    int depth = 0;
};
Node::Node(string str)
{
    nums = str;
    priority = 0;
    next_node = NULL;
    parent = NULL;
}

Node::Node(string num, int prty)
{
    nums = num;
    next_node = NULL;
    parent = NULL;
    priority = prty;
}

Node::Node(string num, Node *node, int prt)
{
    nums = num;
    next_node = node;
    parent = NULL;
    priority = prt;
}

Node::Node(string num, int dept, int prt)
{
    nums = num;
    depth = dept;
    priority = prt;
}

Node::~Node()
{
    delete[] next_node;
    delete[] parent;
}
Node *Node::get_next_node()
{
    return next_node;
}
string Node::get_val()
{
    return nums;
}
void Node::set_val(string num)
{
    nums = num;
}
void Node::set_next(Node *n)
{
    next_node = n;
}
void Node::set_parent(Node *n)
{
    parent = n;
}
Node *Node::get_parent()
{
    return parent;
}
void Node::set_depth(int dept)
{
    depth = dept;
}
int Node::get_depth()
{
    return depth;
}
void Node::set_priority(int prt)
{
    priority = prt;
}
int Node::get_priority()
{
    return priority;
}
#endif