#pragma once

class arrStack
{
private:
	int* data;
	int top;
	int maxSize;
public:
	arrStack();
	arrStack(int size);
	~arrStack();
	void clear();
	bool Push(const int val);
	bool Pop(int& p);
	int Top();//获取栈顶的值
	bool isEmpty();
	bool isFull();
	void showstack();
};