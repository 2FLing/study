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
    Node(string num, Node* node);
    Node(string num, int);
    ~Node();
    string get_val();
    void set_val(string);
    void set_next(Node*);
    void set_parent(Node*);
    Node* get_parent();
    Node* get_next_node();

private:
    string nums;
    Node* next_node;
    Node* parent;
};

Node::Node(string num)
{
    nums = num;
    next_node = NULL;
    parent = NULL;
}

Node::Node(string num, Node* node)
{
    nums = num;
    next_node = node;
    parent = NULL;
}

Node::~Node()
{
    delete[] next_node;
    delete[] parent;
}
Node* Node::get_next_node()
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
void Node::set_next(Node* n)
{
    next_node = n;
}
void Node::set_parent(Node* n)
{
    parent = n;
}
Node* Node::get_parent()
{
    return parent;
}
#endif