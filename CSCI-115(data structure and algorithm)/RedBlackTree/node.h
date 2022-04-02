#ifndef _NODE_H
#define _NODE_H
#include <stdio.h>
#include <string>
using namespace std;
class Node
{
public:
    Node(string);
    Node(string, Node *, Node *, string);
    void set_key(string);
    string get_key();
    Node *get_left();
    Node *get_right();
    void set_left(Node *);
    void set_right(Node *);
    Node *get_parent();
    void set_parent(Node *);
    void set_color(string);
    string get_color();

private:
    string key;
    Node *left;
    Node *right;
    Node *parent;
    string color;
};
Node::Node(string num)
{
    key = num;
    if (key == "NIL")
    {
        color = "black";
        left = NULL;
        right = NULL;
    }
    else
    {
        left = new Node("NIL", NULL, NULL, "black");
        right = new Node("NIL", NULL, NULL, "black");
        color = "red";
    }
    parent = NULL;
}
Node::Node(string num, Node *l, Node *r, string str)
{
    key = num;
    left = l;
    right = r;
    if (l)
        l->set_parent(this);
    if (r)
        r->set_parent(this);
    color = str;
    parent = NULL;
}
void Node::set_key(string num)
{
    key = num;
    if (num == "NIL")
        color = "black";
}
string Node::get_key()
{
    return key;
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
void Node::set_color(string str)
{
    color = str;
}
string Node::get_color()
{
    return color;
}
#endif