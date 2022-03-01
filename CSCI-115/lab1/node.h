#pragma once
#ifndef NODE_
#define NODE_
#include<stdio.h>
using namespace std;
struct node
{
	int val;
	node* next;
	node(int num);
};
node::node(int num)
{
	val = num;
	next = NULL;
}
#endif