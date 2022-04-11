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
	void find(const int val, int& po); //查找位置上元素

private:
	int* aList;  //指针指向数组
	int Maxsize; //最大长度
	int curLen;  //当前数组长度
	int posi;    //当前所指位置
};