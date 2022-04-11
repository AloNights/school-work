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
	List(); //Ĭ�Ϲ��캯��
	List(const List& ls); //�������캯��
	~List(); //Ĭ����������
	void AddEndNode(int val); //β��
	void AddFrontNode(int val); //ͷ��
	void ShowList(); //��ӡ����
	void ReverseShowList(); //�����ӡ����
	bool InsertNode(int val, int loc); //ָ��λ�ò���ڵ�
	void DeleteNode(int val); //ɾ���ڵ�
	void DeleteFrontNode(); //ɾ��ͷ���
	void DeleteEndNode(); //ɾ��β�ڵ�
	void RemoveList(); //��������
	bool Find(int val); //���ҽڵ�
	bool IsEmpty(); //�ж������Ƿ�Ϊ��
};