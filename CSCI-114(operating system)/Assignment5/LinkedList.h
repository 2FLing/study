#pragma once
#ifndef LINKEDLIST_
#define LINKEDLIST_
#include "Node.h"
#include <iostream>
struct linked_list
{
	Node* head;
	linked_list();
	void insert_block(int);
	void insert_request(int, int, int);
	void insert_node(Node*);
	int allocate(int, int);
	void release(int);
	bool delete_node(Node*);
	int find_best(int);
	int get_bid(int);
	linked_list* sort();
};

linked_list::linked_list()
{
	head = NULL;
}
int linked_list::find_best(int memory_size)
{
	sort();
	Node* temp = head;
	int res=-1;
	while (temp)
	{
		if (temp->free_memory_size >= memory_size)
		{
			res = temp->block_id;
			break;
		}
		temp = temp->next;
	}
	return res;
}
int linked_list::get_bid(int rid)
{
	int bid;
	Node* temp = head;
	while (temp)
	{
		if (temp->request_id == rid)
		{
			bid = temp->block_id;
			break;
		}
		temp = temp->next;
	}
	return bid;
}
void linked_list::insert_node(Node* node)
{
	if (!head)
		head = node;
	else
	{
		Node* temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = node;
	}
}
void linked_list::insert_block(int bid)
{
	Node* new_node = new Node();
	new_node->make_block(bid);
	insert_node(new_node);
}
void linked_list::insert_request(int rid, int bid, int size)
{
	Node* new_node = new Node();
	new_node->make_request(rid, bid, size);
	insert_node(new_node);
}
int linked_list::allocate(int bid, int size)
{
	Node* temp = head;
	while (temp)
	{
		if (temp->block_id == bid)
		{
			temp->free_memory_size -= size;
			break;
		}
		temp = temp->next;
	}
	return temp->block_id;
}
void linked_list::release(int bid)
{
	Node* temp = head;
	while (temp)
	{
		if (temp->block_id == bid)
		{
			temp->free_memory_size = 1024;
			break;
		}
		temp = temp->next;
	}
}
bool linked_list::delete_node(Node* node)
{
	bool res;
	if (!head)
		res = false;
	else
	{
		if (!node->next)
		{
			node = NULL;
			delete (node);
		}
		else if (node == head)
		{
			Node* temp = head;
			head = head->next;
			temp = NULL;
			delete(temp);
		}
		else
		{
			Node* temp = head, * pre = temp;
			while (head)
			{
				temp = temp->next;
				if (temp == node)
				{
					pre->next = temp->next;
					temp = NULL;
					delete (temp);
					break;
				}
				pre = temp;
			}
		}
		res = true;
	}
	return res;
}
// after sorting the original list will be empty
// so have to assign the result to the orignal list.
linked_list* linked_list::sort()
{
	linked_list* new_list = new linked_list();
	Node* temp=head;
	while (temp)
	{
		temp = head;
		Node* min = temp;
		while (temp)
		{
			if (temp->free_memory_size < min->free_memory_size)
				min = temp;
			temp = temp->next;
		}
		if (min)
		{
			new_list->insert_node(min);
			delete_node(min);
		}
	}
	head = new_list->head;
	return new_list;
}
#endif