#pragma once
#ifndef NODE_
#define NODE_
#include<stdio.h>
using namespace std;
struct Node
{
    int block_id;
    int request_id;
    int free_memory_size;
    int memory_size;
    Node* next;
    void make_block(int);
    void make_request(int, int,int);
};
void Node::make_block(int bid)
{
    block_id = bid;
    free_memory_size = 1024;
    next = NULL;
}
void Node::make_request(int rid, int bid,int m_size)
{
    request_id = rid;
    block_id = bid;
    memory_size = m_size;
    next = NULL;
}

#endif