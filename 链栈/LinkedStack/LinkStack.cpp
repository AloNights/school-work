#include "linkedSatck.h"
#include<iostream>

using namespace std;

LinkStack::LinkStack()
{
	top = NULL;
}

bool LinkStack::Push(const char val)
{
	Node* tem = new Node;
	tem->value = val;
	tem->next = NULL;
	tem->last = top;
	if (top != NULL)
	{
		top->next = tem;
	}
	top = tem;
	return true;
}

bool LinkStack::Pop(char& p)
{
	if (top == NULL)
		return false;
	Node* tem = top;
	p = tem->value;
	top = top->last;
	if (top != NULL)
		top->next = NULL;
	delete tem;
	return true;
}

char LinkStack::Top()
{
	return top->value;
}

LinkStack::~LinkStack()
{
	char num;
	Node* tem = top;
	while (top != NULL)
	{
		tem = top;
		top = top->last;
		delete tem;
	}
}

bool LinkStack::isEmpty()
{
	if (top == NULL)
		return true;
	else
		return false;
}

void LinkStack::showStack()
{
	Node* tem = top;
	while (tem != NULL)
	{
		cout << tem->value << " ";
		tem = tem->last;
	}
	cout << endl;
}