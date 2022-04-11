#pragma once
#ifndef DLL_IMPORT
#define HEAD extern "C"
#define API __declspec(dllexport) 
#else
#define HEAD extern "C"
#define API __declspec(dllimport) 
#endif // !DLL_IMPORT

typedef API struct _ListNode {
	int data;
	struct _ListNode* next;
}ListNode;

class API List
{
private:
	ListNode* head;
	int length;

public:
	List(); //默认构造函数
	List(const List& ls); //拷贝构造函数
	~List(); //默认析构函数
	void AddEndNode(int val); //尾插
	void AddFrontNode(int val); //头插
	void ShowList(); //打印链表
	void ReverseShowList(); //反向打印链表
	bool InsertNode(int val, int loc); //指定位置插入节点
	void DeleteNode(int val); //删除节点
	void DeleteFrontNode(); //删除头结点
	void DeleteEndNode(); //删除尾节点
	void RemoveList(); //销毁链表
	bool Find(int val); //查找节点
	bool IsEmpty(); //判断链表是否为空
};