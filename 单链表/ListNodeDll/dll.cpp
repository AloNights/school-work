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

//拷贝构造函数
List::List(const List& ls)
{
	// 初始化
	head = new ListNode;
	ListNode* pr = ls.head->next;
	ListNode* p = head;

	// 遍历链表赋值
	while (pr != nullptr) {
		ListNode* tmp = new ListNode;
		tmp->data = pr->data;
		tmp->next = nullptr;
		p->next = tmp;
		// 节点前移
		p = p->next;
		pr = pr->next;
	}

	length = ls.length;
}

// 析构函数
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

// 尾插
void List::AddEndNode(int val)
{
	ListNode* p = head;
	//遍历到链表尾部
	while (p->next != nullptr) {
		p = p->next;
	}
	//添加节点
	ListNode* s = new ListNode;
	s->data = val;
	s->next = nullptr;
	p->next = s;
	++length;
}

// 头插
void List::AddFrontNode(int val)
{
	ListNode* newNode = new ListNode;
	newNode->data = val;
	newNode->next = head->next;//加进来的结点指向尾部
	head->next = newNode;
	++length;
}

// 输出链表
void List::ShowList()
{
	// 链表是否为空
	if (!length) {
		cout << "List is empty!" << endl;
		return;
	}

	ListNode* p = head->next;//指向头结点
	// 遍历链表打印
	while (p != nullptr) {
		cout << p->data << endl;
		p = p->next;
	}
	cout << "输出完毕" << endl;
}

//反向打印链表
void List::ReverseShowList()
{
	//采用栈来反向输出
	stack<int> s;

	ListNode* p = head->next;
	while (p != nullptr) {
		s.push(p->data);
		p = p->next;
	}

	// 栈输出
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << "反向输出完毕" << endl;
}

// 在某节点后插入节点
bool List::InsertNode(int val, int loc)
{
	int i = 0;
	ListNode* p = head;
	if (loc <= 0)
	{
		cout << "输入位置错误" << endl;
		return false;
	}
	while (p != nullptr && i < loc - 1) {
		i++;
		p = p->next;
	}
	if (p == NULL)
	{
		cout << "未找到" << endl;
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

// 根据值删除某个节点
void List::DeleteNode(int val)
{
	// 链表是否为空
	if (!length) {
		cout << "List is empty!" << endl;
		return;
	}

	// pre是p的上一个节点
	// 在删除时不需要重新遍历第二遍
	ListNode* p = head->next;
	ListNode* pre = head;
	bool found = false;
	// 遍历到需要删除的节点
	while (p != nullptr) {
		if (val == p->data) {
			found = true;
			break;
		}
		// 节点后移
		p = p->next;
		pre = pre->next;
	}

	if (!found) {
		cout << "Node not been found!" << endl;
		return;
	}
	else {
		// 删除节点
		pre->next = p->next;
		delete p;
		p = nullptr;
		--length;
	}
}

// 删除头部节点
void List::DeleteFrontNode()
{
	// 链表是否为空
	if (!length) {
		cout << "List is empty!" << endl;
		return;
	}

	// 删除头部节点
	ListNode* del = head->next;
	head->next = del->next;
	delete del;
	del = nullptr;
}

// 删除尾部节点
void List::DeleteEndNode()
{
	// 链表是否为空
	if (!length) {
		cout << "List is empty!" << endl;
		return;
	}

	ListNode* pre = head;
	ListNode* del = head->next;
	// 遍历到链表尾部
	while (del->next != nullptr) {
		del = del->next;
		pre = pre->next;
	}

	delete del;
	del = nullptr;
	pre->next = nullptr;
}

// 销毁链表
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

// 查找节点
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

// 判断链表是否为空
bool List::IsEmpty()
{
	return length == 0;
}