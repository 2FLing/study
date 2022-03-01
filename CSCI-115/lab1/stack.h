#pragma once
#ifndef STACK_
#define STACK_
#include<cstdlib>
#include<iostream>
using namespace std;
class stack
{
private:
	int nums[10];
	int top = -1;
public:
	void push(int num);
	int pop();
	int peek();
	void display();
};
void stack::push(int num)
{
	if(top<9)
	{
		top = top + 1;
		nums[top] = num;
	}
	else
		throw "Stack is already full!";
}
int stack::pop()
{
	if (top == -1)
		throw "Stack is empty!";
	else
	{
		top = top - 1;
		return nums[top + 1];
	}
}
int stack::peek()
{
	if (top == -1)
	{
		throw "Stack is empty!";
		exit(1);
	}
	else
	{
		return nums[top];
	}
}
void stack::display()
{
	cout << "Items in the stack:";
	for (int i = top; i >= 0; i--)
	{
		if (i == 0)
		{
			cout << nums[i] << endl;
		}
		else
			cout << nums[i] << ",";
	}
}
#endif