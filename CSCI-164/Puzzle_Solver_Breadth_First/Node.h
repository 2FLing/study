#ifndef _NODE
#define _NODE
#include <string>
#include <stdio.h>
using namespace std;
class Node
{
public:
    Node(string);
    Node(string, Node *node);
    ~Node();
    string get_val();
    void set_val(string);
    void set_next(Node *);
    void set_parent(Node *);
    Node *get_parent();
    Node *get_next_node();

private:
    string state;
    Node *next_node;
    Node *parent;
};

Node::Node(string str)
{
    state = str;
    next_node = NULL;
    parent = NULL;
}

Node::Node(string str, Node *node)
{
    state = str;
    next_node = node;
    parent = NULL;
}

Node::~Node()
{
    delete[] next_node;
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
#endif