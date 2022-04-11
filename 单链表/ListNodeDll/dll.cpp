#include"dll.h"
#include<iostream>
#include<stack>
using namespace std;

List::List()
{
	head = new ListNode;
	head->next = nullptr;
	length = 0;
}

//�������캯��
List::List(const List& ls)
{
	// ��ʼ��
	head = new ListNode;
	ListNode* pr = ls.head->next;
	ListNode* p = head;

	// ��������ֵ
	while (pr != nullptr) {
		ListNode* tmp = new ListNode;
		tmp->data = pr->data;
		tmp->next = nullptr;
		p->next = tmp;
		// �ڵ�ǰ��
		p = p->next;
		pr = pr->next;
	}

	length = ls.length;
}

// ��������
List::~List()
{
	if (length) {
		RemoveList();
		delete head;
		head = nullptr;
		cout << "Released!" << endl;
	}
	else {
		delete head;
		head = nullptr;
		cout << "0 Released!" << endl;
	}
}

// β��
void List::AddEndNode(int val)
{
	ListNode* p = head;
	//����������β��
	while (p->next != nullptr) {
		p = p->next;
	}
	//��ӽڵ�
	ListNode* s = new ListNode;
	s->data = val;
	s->next = nullptr;
	p->next = s;
	++length;
}

// ͷ��
void List::AddFrontNode(int val)
{
	ListNode* newNode = new ListNode;
	newNode->data = val;
	newNode->next = head->next;//�ӽ����Ľ��ָ��β��
	head->next = newNode;
	++length;
}

// �������
void List::ShowList()
{
	// �����Ƿ�Ϊ��
	if (!length) {
		cout << "List is empty!" << endl;
		return;
	}

	ListNode* p = head->next;//ָ��ͷ���
	// ���������ӡ
	while (p != nullptr) {
		cout << p->data << endl;
		p = p->next;
	}
	cout << "������" << endl;
}

//�����ӡ����
void List::ReverseShowList()
{
	//����ջ���������
	stack<int> s;

	ListNode* p = head->next;
	while (p != nullptr) {
		s.push(p->data);
		p = p->next;
	}

	// ջ���
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << "����������" << endl;
}

// ��ĳ�ڵ�����ڵ�
bool List::InsertNode(int val, int loc)
{
	int i = 0;
	ListNode* p = head;
	if (loc <= 0)
	{
		cout << "����λ�ô���" << endl;
		return false;
	}
	while (p != nullptr && i < loc - 1) {
		i++;
		p = p->next;
	}
	if (p == NULL)
	{
		cout << "δ�ҵ�" << endl;
		return false;
	}
	else
	{
		ListNode* s = new ListNode;
		s->data = val;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

// ����ֵɾ��ĳ���ڵ�
void List::DeleteNode(int val)
{
	// �����Ƿ�Ϊ��
	if (!length) {
		cout << "List is empty!" << endl;
		return;
	}

	// pre��p����һ���ڵ�
	// ��ɾ��ʱ����Ҫ���±����ڶ���
	ListNode* p = head->next;
	ListNode* pre = head;
	bool found = false;
	// ��������Ҫɾ���Ľڵ�
	while (p != nullptr) {
		if (val == p->data) {
			found = true;
			break;
		}
		// �ڵ����
		p = p->next;
		pre = pre->next;
	}

	if (!found) {
		cout << "Node not been found!" << endl;
		return;
	}
	else {
		// ɾ���ڵ�
		pre->next = p->next;
		delete p;
		p = nullptr;
		--length;
	}
}

// ɾ��ͷ���ڵ�
void List::DeleteFrontNode()
{
	// �����Ƿ�Ϊ��
	if (!length) {
		cout << "List is empty!" << endl;
		return;
	}

	// ɾ��ͷ���ڵ�
	ListNode* del = head->next;
	head->next = del->next;
	delete del;
	del = nullptr;
}

// ɾ��β���ڵ�
void List::DeleteEndNode()
{
	// �����Ƿ�Ϊ��
	if (!length) {
		cout << "List is empty!" << endl;
		return;
	}

	ListNode* pre = head;
	ListNode* del = head->next;
	// ����������β��
	while (del->next != nullptr) {
		del = del->next;
		pre = pre->next;
	}

	delete del;
	del = nullptr;
	pre->next = nullptr;
}

// ��������
void List::RemoveList()
{
	ListNode* p = head;
	ListNode* del;

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

// ���ҽڵ�
bool List::Find(int val)
{
	ListNode* p = head->next;

	while (p != nullptr) {
		if (val == p->data) {
			cout << "Node " << val << "been found" << endl;
			return true;
		}
		p = p->next;
	}
	cout << "Node " << val << "not been found" << endl;
	return false;
}

// �ж������Ƿ�Ϊ��
bool List::IsEmpty()
{
	return length == 0;
}