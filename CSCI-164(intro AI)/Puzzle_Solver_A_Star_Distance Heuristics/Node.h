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
    Node(string, int);
    Node(string v, Node *node, int);
    ~Node();
    string get_val();
    void set_val(string);
    void set_next(Node *);
    void set_parent(Node *);
    Node *get_parent();
    Node *get_next_node();
    int get_priority();
    void set_priority(int);

private:
    string state;
    Node *next_node;
    Node *parent;
    int priority;
};

Node::Node(string str)
{
    state = str;
    priority = 0;
    next_node = NULL;
    parent = NULL;
}

Node::Node(string str, int prty)
{
    state = str;
    priority = prty;
    next_node = NULL;
    parent = NULL;
}

Node::Node(string str, Node *node, int prty)
{
    state = str;
    next_node = node;
    priority = prty;
    parent = NULL;
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
    return state;
}
void Node::set_val(string str)
{
    state = str;
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
int Node::get_priority()
{
    return priority;
}
void Node::set_priority(int p)
{
    priority = p;
}
#endif