#ifndef _REDBLACKTREE_
#define _REDBLACKTREE_
#include "node.h"
#include <iostream>
#include<string>
#include <math.h>
#include <stdio.h>
using namespace std;
// 关于双黑红黑等多重颜色的概念有点混淆
class Red_Black_Tree
{
public:
    Red_Black_Tree(string num);
    void insert(string num);
    void remove(string num);
    void pre_order();
    Node *get_root();

private:
    Node *root;
    void transplant(Node *, Node *);
    void left_rotate(Node *);
    void right_rotate(Node *);
    Node *tree_maximum(Node *);
    Node *tree_minimum(Node *);
    void insert_helper(string num);
    void delete_helper(Node *);
    void insert_fix_up(Node *node);
    void delete_fix_up(Node *node, Node *replace_node);
    void pre_order_helper(Node *node);
    void double_black_fixer(Node *, Node *);
};
Node *Red_Black_Tree::get_root()
{
    return root;
}
Red_Black_Tree::Red_Black_Tree(string num)
{
    root = new Node(num);
}

void Red_Black_Tree::transplant(Node *u, Node *v)
{
    Node *u_p = u->get_parent();
    if (!u)
        root = v;
    else if (u_p->get_left() == u)
        u_p->set_left(v);
    else
        u_p->set_right(v);
    v->set_parent(u_p);
}
void Red_Black_Tree::left_rotate(Node *node)
{
    if (node->get_right())
    {
        Node *right_node = node->get_right();
        Node *right_node_left = right_node->get_left();
        node->set_right(right_node_left);
        Node *node_p = node->get_parent();
        if (!node_p)
            root = right_node;
        else if (node_p->get_left() == node)
            node_p->set_left(right_node);
        else
            node_p->set_right(right_node);
        right_node->set_parent(node->get_parent());
        right_node->set_left(node);
    }
}
void Red_Black_Tree::right_rotate(Node *node)
{
    if (node->get_left())
    {
        Node *left_node = node->get_left();
        Node *left_node_right = left_node->get_right();
        node->set_left(left_node_right);
        Node *node_p = node->get_parent();
        if (!node_p)
            root = left_node;
        else if (node_p->get_left() == node)
            node_p->set_left(left_node);
        else
            node_p->set_right(left_node);
        left_node->set_parent(node->get_parent());
        left_node->set_right(node);
    }
}
void Red_Black_Tree::insert_fix_up(Node *node)
{
    Node *temp = root;
    while (temp != node)
    {
        if (stoi(temp->get_key()) < stoi(node->get_key()))
            temp = temp->get_right();
        else
            temp = temp->get_left();
    }
    Node *parent = temp->get_parent();
    Node *grand_p = parent->get_parent();
    while (parent && grand_p && parent->get_color() == "red")
    {
        if (grand_p->get_left() == parent)
        {
            Node *sibling = grand_p->get_right();
            if (sibling->get_color() == "red")
            {
                sibling->set_color("black");
                parent->set_color("black");
                grand_p->set_color("red");
                temp = grand_p;
            }
            else
            {
                if (parent->get_right() == temp)
                {
                    temp = parent;
                    left_rotate(temp);
                }
                temp->get_parent()->set_color("black");
                temp->get_parent()->get_parent()->set_color("red");
                right_rotate(temp->get_parent()->get_parent());
            }
        }
        else
        {
            Node *sibling = grand_p->get_left();
            if (sibling->get_color() == "red")
            {
                sibling->set_color("black");
                parent->set_color("black");
                grand_p->set_color("red");
                temp = grand_p;
            }
            else
            {
                if (parent->get_left() == temp)
                {
                    temp = parent;
                    right_rotate(temp);
                }
                temp->get_parent()->set_color("black");
                temp->get_parent()->get_parent()->set_color("red");
                left_rotate(temp->get_parent()->get_parent());
            }
        }
        if (temp == root)
            break;
        parent = temp->get_parent();
        grand_p = parent->get_parent();
    }
    root->set_color("black");
}
Node *Red_Black_Tree::tree_maximum(Node *node)
{
    Node *max = NULL;
    while (node->get_key() != "NIL")
    {
        max = node;
        node = node->get_right();
    }
    return max;
}
Node *Red_Black_Tree::tree_minimum(Node *node)
{
    Node *min = NULL;
    while (node->get_key() != "NIL")
    {
        min = node;
        node = node->get_left();
    }
    return min;
}
void Red_Black_Tree::insert_helper(string num)
{
    Node *temp = root;
    Node *y = NULL;
    while (temp->get_key() != "NIL")
    {
        y = temp;
        if (stoi(temp->get_key()) < stoi(num))
            temp = temp->get_right();
        else
            temp = temp->get_left();
    }
    Node *left = new Node("NIL"), *right = new Node("NIL");
    Node *new_node = new Node(num);
    if (!y)
        root = new Node(num, left, right, "black");
    else
    {
        if (stoi(y->get_key()) < stoi(num))
            y->set_right(new_node);
        else
            y->set_left(new_node);
        insert_fix_up(new_node);
    }
}
void Red_Black_Tree::insert(string num)
{
    insert_helper(num);
}
void Red_Black_Tree::double_black_fixer(Node *parent, Node *sibling)
{
    Node *grand_p = sibling->get_parent();
    string original_color = parent->get_color();
    if(original_color=="black")
    {
        sibling->set_color("red");
    }
    else
    {
        parent->set_color("black");
        sibling->set_color("red");
    }
    if (grand_p && original_color!="red")
    {
        Node * parent_sibling;
        if(grand_p->get_left() == parent)
            parent_sibling = grand_p->get_right();
        else
            parent_sibling = grand_p->get_left();
        double_black_fixer(grand_p,parent_sibling);
    }
}
void Red_Black_Tree::delete_fix_up(Node *node, Node *replace_node)
{
    string node_color = node->get_color();
    string replace_color = replace_node->get_color();
    if (node_color == "black")
    {
        if (replace_color == "red")
        {
            replace_node->set_color("black");
        }
        else
        {
            Node *parent = node->get_parent();
            if (parent->get_right() == node)
            {
                Node *sibling = parent->get_left();
                Node *left_cousin = sibling->get_left();
                Node *right_cousin = sibling->get_right();
                if (left_cousin->get_color() == "red" || right_cousin->get_color() == "red")
                {
                    if (left_cousin->get_key() != "NIL")
                    {
                        left_cousin->set_color(sibling->get_color());
                        sibling->set_color(parent->get_color());
                        right_rotate(parent);
                    }
                    else
                    {
                        right_cousin->set_color(parent->get_color());
                        left_rotate(sibling);
                        right_rotate(parent);
                    }
                    parent->set_color("black");
                }
                else
                {
                    double_black_fixer(parent,sibling);
                }
            }
            else
            {
                Node *sibling = parent->get_right();
                Node *left_cousin = sibling->get_left();
                Node *right_cousin = sibling->get_right();
                if (left_cousin->get_color() == "red" || right_cousin->get_color() == "red")
                {
                    if (right_cousin->get_key() != "NIL")
                    {
                        right_cousin->set_color(sibling->get_color());
                        sibling->set_color(parent->get_color());
                        left_rotate(parent);
                    }
                    else
                    {
                        left_cousin->set_color(parent->get_color());
                        right_rotate(sibling);
                        left_rotate(parent);
                    }
                    parent->set_color("black");
                }
                else
                {
                    double_black_fixer(parent,sibling);
                }
            }
        }
    }
}
void Red_Black_Tree::delete_helper(Node *node)
{
    string original_color = node->get_color();
    Node *lelft_child = node->get_left();
    Node *right_child = node->get_right();
    Node *replace_child;
    if (lelft_child->get_key() == "NIL")
    {
        transplant(node, right_child);
        replace_child = right_child;
    }
    else if (right_child->get_key() == "NIL")
    {
        transplant(node, lelft_child);
        replace_child = lelft_child;
    }
    else
    {
        Node *right_min = tree_minimum(right_child);
        original_color = right_min->get_color();
        if (right_min != right_child)
        {
            transplant(right_min, right_min->get_right());
        }
        transplant(node, right_min);
        right_min->set_left(node->get_left());
        right_min->set_right(node->get_right());
        replace_child = right_min;
    }
    if (original_color == "black")
        delete_fix_up(node, replace_child);
}
void Red_Black_Tree::pre_order_helper(Node *node)
{
    if (node->get_key() != "NIL")
    {
        cout << node->get_key() << " " << node->get_color() << " ";
    }
    if (node->get_left()->get_key() != "NIL")
        pre_order_helper(node->get_left());
    if (node->get_right()->get_key() != "NIL")
        pre_order_helper(node->get_right());
}
void Red_Black_Tree::remove(string num)
{
    Node* temp = root;
    if(temp->get_key() == num)
        root = NULL;
    else
    {
        Node* y = NULL;
        while(temp->get_key()!="NIL")
        {
            y = temp;
            if(stoi(temp->get_key())<stoi(num))
                temp = temp->get_right();
            else
                temp = temp->get_left();
        }
        delete_helper(temp);
    }
}
void Red_Black_Tree::pre_order()
{
    pre_order_helper(root);
}
#endif