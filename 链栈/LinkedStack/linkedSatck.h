#pragma once

typedef struct node
{
	char value;
	node* next;
	node* last;
}Node;

class LinkStack
{
private:
	Node* top;
public:
	LinkStack();
	~LinkStack();
	bool Push(const char val);
	bool Pop(char& p);
	char Top();
	void showStack(); //Êä³öÕ»
	bool isEmpty();
};
