#include "arrStack.h"
#include <iostream>

using namespace std;

arrStack::arrStack()
{
	top = -1;
}

arrStack::arrStack(int size)
{
	maxSize = size;
	top = -1;
	data = new int[maxSize];
}

arrStack::~arrStack()
{
	delete[]data;
}

void arrStack::clear()
{
	top = -1;
}

bool arrStack::isEmpty()
{
	return top == -1;
}

bool arrStack::isFull()
{
	return top == maxSize;
}

bool arrStack::Push(const int p)
{
	if (top == maxSize - 1)
	{
		cout << "Õ»Òç³ö" << endl;
		return false;
	}
	else
	{
		data[++top] = p;
		return true;
	}
}

bool arrStack::Pop(int& val)
{
	if (top == -1)
	{
		cout << "Õ»¿Õ" << endl;
		return false;
	}
	else {
		val = data[top--];
		return true;
	}
}

int arrStack::Top()
{
	return data[top];
}

void arrStack::showstack()
{
	if (top == -1)
		cout << "Stack is empty";
	for (int i = 0; i <= top; i++)
	{
		cout << data[i] << "";
	}
	cout << endl;
}