#pragma once

class arrList
{
public:
	arrList(const int size);
	~arrList();
	int getlength();
	bool append(const int val);
	void showList();
	bool insert(const int p, const int val);
	bool del(const int p);
	bool isEmpty();
	void find(const int val, int& po); //����λ����Ԫ��

private:
	int* aList;  //ָ��ָ������
	int Maxsize; //��󳤶�
	int curLen;  //��ǰ���鳤��
	int posi;    //��ǰ��ָλ��
};