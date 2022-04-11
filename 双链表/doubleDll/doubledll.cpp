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
	//��������ֵ
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

// β��
void DoubleLink::AddEndNode(int val)
{
	DoubleListNode* p = head;
	//����������β��
	while (p->next != NULL) {
		p = p->next;
	}
	//��ӽڵ�
	DoubleListNode* s = new DoubleListNode;
	s->data = val;
	s->next = NULL;
	p->next = s;
	s->front = p;
	++length;
}

// ͷ��
void DoubleLink::AddFrontNode(int val)
{
	DoubleListNode* newNode = new DoubleListNode;
	newNode->data = val;
	newNode->next = head->next;//�ӽ����Ľ��ָ��β��
	head->next = newNode;
	newNode->front = head;
	++length;
}

int DoubleLink::Size()
{
	return length;
}

// �������
void DoubleLink::ShowList()
{
	// �����Ƿ�Ϊ��
	if (!length) {
		cout << "List is empty!" << endl;
		return;
	}

	DoubleListNode* p = head->next;//ָ��ͷ���
	// ���������ӡ
	while (p != nullptr) {
		cout << p->data << endl;
		p = p->next;
	}
	cout << "������" << endl;
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
		cout << "δ�ҵ�ָ�����" << endl;
		return NULL;
	}
	return p->data;
}

//��ָ����������
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
		cout << "δ�ҵ�ָ�����" << endl;
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
		cout << "δ�ҵ�ָ�����" << endl;
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

//����
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