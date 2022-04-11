#pragma once
#ifndef DLL_IMPORT
#define HEAD extern "C"
#define API __declspec(dllexport) 
#else
#define HEAD extern "C"
#define API __declspec(dllimport) 
#endif // !DLL_IMPORT

typedef API struct DoubleListNode {
	int data;
	struct DoubleListNode* front;
	struct DoubleListNode* next;
}DbListNode;

class API DoubleLink
{
private:
	DbListNode* head;
	
public:
	int length;
	DoubleLink(); //默认构造函数
	DoubleLink(const DoubleLink& ls); //拷贝构造函数
	void AddEndNode(int val); //尾插
	void AddFrontNode(int val); //头插
	int Size();//获取链表长度
	void ShowList(); //打印链表
	int Find(int index); //获取结点的值
	bool InsertNode(int val, int loc); //指定位置插入节点
	void DeleteNode(int index); //删除节点
	void DeleteFristNode(); //删除头结点
	void DeleteEndNode(); //删除尾节点
	void RemoveList(); //销毁链表
	bool IsEmpty(); //判断链表是否为空
	int getlength();
};