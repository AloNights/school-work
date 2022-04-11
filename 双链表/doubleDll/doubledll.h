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
	DoubleLink(); //Ĭ�Ϲ��캯��
	DoubleLink(const DoubleLink& ls); //�������캯��
	void AddEndNode(int val); //β��
	void AddFrontNode(int val); //ͷ��
	int Size();//��ȡ������
	void ShowList(); //��ӡ����
	int Find(int index); //��ȡ����ֵ
	bool InsertNode(int val, int loc); //ָ��λ�ò���ڵ�
	void DeleteNode(int index); //ɾ���ڵ�
	void DeleteFristNode(); //ɾ��ͷ���
	void DeleteEndNode(); //ɾ��β�ڵ�
	void RemoveList(); //��������
	bool IsEmpty(); //�ж������Ƿ�Ϊ��
	int getlength();
};