#ifndef _BINARYSEARCHTREE
#define _BINARYSEARCHTREE
#include "node.h"
#include <iostream>
class BST
{
public:
    BST();
    BST(int);
    void insert(int);
    void remove(int);
    void in_order();
    void pre_order();
    void post_order();
    void search(int);
    int minimum_tree();
    int maximum_tree();

private:
    Node* root;
    Node* insert_helper(Node*, int);
    void post_order_helper(Node*);
    Node* get_left_most(Node*);
    Node* get_right_least(Node*);
    void right_rotate(Node*);
    void left_rotate(Node*);
    void remove_node(Node*);
    Node* search_node(int);
    void transplant(Node*, Node*);
    void fix_up(Node*);
};
BST::BST()
{
    root = NULL;
}
BST::BST(int num)
{
    root = new Node(num);
}
Node* BST::insert_helper(Node* node, int num)
{
    if (node == NULL)
    {
        node = new Node(num);
    }
    else if (node->get_val() != num)
    {
        if (num < node->get_val())
            node->set_left(insert_helper(node->get_left(), num));
        else
            node->set_right(insert_helper(node->get_right(), num));
    }
    return node;
}
void BST::insert(int num)
{
    root = insert_helper(root, num);
}
void BST::post_order_helper(Node* node)
{
    if (node)
    {
        post_order_helper(node->get_left());

        post_order_helper(node->get_right());
        cout << node->get_val() << " ";
    }
}
void BST::post_order()
{
    post_order_helper(root);
}
Node* BST::get_left_most(Node* node)
{
    if (!node)
        return node;
    else if (!node->get_right())
        return node;
    else
        return get_left_most(node->get_right());
}
Node* BST::get_right_least(Node* node)
{
    if (!node)
        return node;
    else if (!node->get_left())
        return node;
    else
        return get_right_least(node->get_left());
}
int BST::minimum_tree()
{
    if (!root)
    {
        cout << "Empty Tree!";
        return -1;
    }
    else
    {
        Node* temp = root, * y = NULL;
        while (temp)
        {
            y = temp;
            temp = temp->get_left();
        }
        return y->get_val();
    }
}
int BST::maximum_tree()
{
    if (!root)
    {
        cout << "Empty Tree!";
        return -1;
    }
    else
    {
        Node* temp = root, * y = NULL;
        while (temp)
        {
            y = temp;
            temp = temp->get_right();
        }
        return y->get_val();
    }
}
void BST::transplant(Node* u, Node* v)
{
    Node* u_parent = u;
    if (!u_parent)
        root = v;
    else if (u_parent->get_left() == v)
        u_parent->set_left(v);
    else
        u_parent->set_right(v);
}
void BST::left_rotate(Node* node)
{
}
void BST::right_rotate(Node* node)
{
}
Node* BST::search_node(int num)
{
    Node* temp = root;
    if (temp->get_val() == num)
    {
        return temp;
    }
    else
    {
        Node* y = NULL;
        while (temp)
        {
            if (temp->get_val() == num)
                y = temp;
            if (temp->get_val() < num)
                temp = temp->get_right();
            else
                temp = temp->get_left();
        }
        temp = y;
    }
    return temp;
}
void BST::remove_node(Node* node)
{
    if (!node->get_right())
    {
        transplant(node, node->get_left());
    }
    else if (!node->get_left())
    {
        transplant(node, node->get_right());
    }
    else
    {
        Node* right_least = get_right_least(node);
        if (node->get_right() == right_least)
        {
            transplant(node, node->get_right());
        }
        else
        {
            transplant(right_least, right_least->get_right());
            right_least->set_right(node->get_right());
            right_least->set_left(node->get_left());
            Node* node_parent = node->get_parent();
            if (!node_parent)
                root = right_least;
            else
            {
                if (node_parent->get_left() == node)
                    node_parent->set_left(right_least);
                else
                    node_parent->set_right(right_least);
            }
        }
    }
}
void BST::remove(int num)
{
    Node* temp = search_node(num);
    remove_node(temp);
}
void BST::search(int num)
{
    Node* temp = search_node(num);
    if (!temp)
        cout << num << " not found!" << endl;
    else
        cout << num << endl;
}
#endif