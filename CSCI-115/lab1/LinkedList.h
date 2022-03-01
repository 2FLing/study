#pragma once
#ifndef LINKEDLIST_
#define LINKEDLIST_
#include "node.h"
#include<iostream>
class linked_list
{
private:
	node* head = NULL;

public:
	void insert(int num);
	void delete_begin();
	void delete_end();
	void display();
};
void linked_list::insert(int num)
{
	node* new_node = new node(num);
	if (head ==  NULL)
	{
		head = new_node;
	}
	else
	{
		new_node->next = head;
		head = new_node;
	}
}
void linked_list::delete_begin()
{
	if (head)
	{
		node* temp = head;
		head = head->next;
		delete temp;
	}
}
void linked_list::delete_end()
{
	if (head or head->next)
	{
		node* temp, *tail;
		tail = head;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		temp = tail->next;
		tail->next = NULL;
		delete temp;
	}
}
void linked_list::display()
{
	node* temp = head;
	while (temp)
	{
		if (temp->next == NULL)
			cout << temp->val << endl;
		else
		{
			cout << temp->val << ",";
		}
		temp = temp->next;
	}
}
#endif