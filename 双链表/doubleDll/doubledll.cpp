#include"doubledll.h"
#include<iostream>
using namespace std;

DoubleLink::DoubleLink()
{
	head = new DoubleListNode;
	head->front = NULL;
	head->next = NULL;
	head->data = NULL;
	length = 0;
}

DoubleLink::DoubleLink(const DoubleLink& ls)
{
	head = new DoubleListNode;
	DoubleListNode* pr = ls.head->next;
	DoubleListNode* p = head;
	//遍历链表赋值
	while (pr!=NULL)
	{
		DoubleListNode* tmp = new DoubleListNode;
		tmp->data = pr->data;
		tmp->next = nullptr;
		p->next = tmp;
		tmp->front = p;
		p = p->next;
		pr = pr->next;
	}
	length = ls.length;
}

// 尾插
void DoubleLink::AddEndNode(int val)
{
	DoubleListNode* p = head;
	//遍历到链表尾部
	while (p->next != NULL) {
		p = p->next;
	}
	//添加节点
	DoubleListNode* s = new DoubleListNode;
	s->data = val;
	s->next = NULL;
	p->next = s;
	s->front = p;
	++length;
}

// 头插
void DoubleLink::AddFrontNode(int val)
{
	DoubleListNode* newNode = new DoubleListNode;
	newNode->data = val;
	newNode->next = head->next;//加进来的结点指向尾部
	head->next = newNode;
	newNode->front = head;
	++length;
}

int DoubleLink::Size()
{
	return length;
}

// 输出链表
void DoubleLink::ShowList()
{
	// 链表是否为空
	if (!length) {
		cout << "List is empty!" << endl;
		return;
	}

	DoubleListNode* p = head->next;//指向头结点
	// 遍历链表打印
	while (p != nullptr) {
		cout << p->data << endl;
		p = p->next;
	}
	cout << "输出完毕" << endl;
}

int DoubleLink::Find(int index)
{
	if (index<0||index>=length)
	{
		cout << "get node failed! the index in out of bound!" << endl;
		return NULL;
	}
	int i = 0;
	DoubleListNode* p = head->next;
	while (p != nullptr && i < index - 1)
	{
		i++;
		p = p->next;
	}
	if (p == NULL)
	{
		cout << "未找到指定结点" << endl;
		return NULL;
	}
	return p->data;
}

//在指定结点插入结点
bool DoubleLink::InsertNode(int val, int loc)
{
	if (loc >= length)
	{
		cout << "illegal data" << endl;
		return false;
	}
	int i = 0;
	DoubleListNode* p = head;
	while (p!=nullptr&&i<loc-1)
	{
		i++;
		p = p->next;
	}
	if (p == NULL)
	{
		cout << "未找到指定结点" << endl;
		return false;
	}
	else
	{
		DoubleListNode* s = new DoubleListNode;
		s->data = val;
		s->next = p->next;
		p->next->front = s;
		s->front = p;
		p->next = s;
		++length;
		return true;
	}
}

void DoubleLink::DeleteNode(int index)
{
	if (index < 0 || index > length)
	{
		cout << "get node failed! the index in out of bound!" << endl;
		return;
	}
	int i = 0;
	DoubleListNode* p = head->next;
	while (p != nullptr && i < index - 1)
	{
		i++;
		p = p->next;
	}
	if (p == NULL)
	{
		cout << "未找到指定结点" << endl;
		return ;
	}
	else
	{
		cout << p->data << endl;
		p->front->next = p->next;
		p->next->front = p->front;
		p->next = NULL;
		p->front = NULL;
	}
}

void DoubleLink::DeleteFristNode()
{
	DeleteNode(0);
}

void DoubleLink::DeleteEndNode()
{
	DeleteNode(length-1);
}

//销毁
void DoubleLink::RemoveList()
{
	DoubleListNode* p = head->next;
	DoubleListNode* del;

	while (p != nullptr) {
		del = p;
		p = p->next;
		delete del;
	}

	head->next = nullptr;
	del = nullptr;
	p = nullptr;
	length = 0;
}

bool DoubleLink::IsEmpty()
{
	return length == 0;
}

int DoubleLink::getlength()
{
	return length;
}