#include "class.h"
#include <iostream>

using namespace std;

arrList::arrList(const int size)
{
	Maxsize = size;
	aList = new int[Maxsize];
	curLen = posi = 0;
}

arrList::~arrList()
{
	delete[]aList;
}

int arrList::getlength()
{
	return curLen;
}

bool arrList::isEmpty()
{
	return curLen == 0;
}

bool arrList::append(const int val)
{
	if (curLen > Maxsize)
	{
		cout << "The List is overflow" << endl;
		return false;
	}
	aList[curLen] = val;
	curLen++;
	return true;
}

void arrList::showList()
{
	if (isEmpty())
		cout << "the list is empty" << endl;
	for (int i = 0; i < curLen; i++)
	{
		cout << aList[i] << " ";
	}
	cout << endl;
}

bool arrList::insert(const int p, const int val)
{
	int i;
	if (curLen > Maxsize)
	{
		cout << "The List is overflow" << endl;
		return false;
	}
	if (p<0 || p>curLen)
	{
		cout << "Isertion point is illegal" << endl;
		return false;
	}
	for (i = curLen; i > p; i--)
		aList[i] = aList[i - 1];
	aList[p] = val;
	curLen++;
	return true;
}

bool arrList::del(const int p)
{
	int i;
	if (curLen <= 0)
	{
		cout << "The List is empty" << endl;
		return false;
	}
	if (p<0 || p>curLen)
	{
		cout << "Isertion point is illegal" << endl;
		return false;
	}
	for (i = p; i < curLen; i++)
		aList[i] = aList[i + 1];
	curLen--;
	return true;
}

void arrList::find(const int val, int& po)
{
	int i = 0;
	if (curLen <= 0)
	{
		cout << "The List is empty" << endl;
		return;
	}
	for (i; i < curLen; i++)
	{
		if (aList[i] == val)
		{
			po = i;
			cout << "该值的位置为：" << po + 1 << endl;
			return;
		}
	}
	cout << "cannot find the value" << endl;
}
//#define MaxSize 100
//
////顺序表的建立 
//typedef struct {
//	int data[MaxSize];					// 	存储空间的基地址
//	int length;							//当前长度 
//}SqList;
//
//
//// 顺序表的初始化
//void InitList(SqList& L) {
//	L.length = 0;
//	cout << "顺序表初始化完成" << endl;
//}
//
//// 顺序表传值 
//void CreatList(SqList& L, int n)
//{
//
//	cout << "请传入数值" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> L.data[i];
//		L.length++;
//	}
//}
//
////打印顺序表 
//int Print(SqList L)
//{
//	cout << "目前顺序表为：" << endl;
//	if (L.length == 0)
//	{
//		return 0;
//	}
//	for (int k = 0; k < L.length; k++)		//输出顺序表 
//	{
//		cout << L.data[k] << "\t";
//	}
//	cout << endl;
//}
////查找元素
//int getElem(SqList L)
//{
//	int p;
//	int e;
//	cout << "请输入要查找元素的位置" << endl;
//	cin >> p;
//	if (p<0 || p>L.length - 1)
//	{
//		return 0;
//	}
//	else
//	{
//		e = L.data[p - 1];							// 第p个元素对应数组中的L.data[p-1]
//		cout << "你要查找的元素为：" << e << endl;
//	}
//}
//
////插入元素
//int insertElem(SqList& L)
//{
//	int p, e, i;
//	cout << "请输入要插入的位置及元素" << endl;
//	cin >> p >> e;
//	if (p<0 || p>L.length || L.length == MaxSize)		//判断要插入的位置是否合法并且判断线性表是否达到了最大 
//	{
//		cout << "插入地址不合法" << endl;
//		return 0;
//	}
//	for (i = L.length - 1; i >= p - 1; i--)
//	{
//		L.data[i + 1] = L.data[i];					//从后往前，逐个将元素后移 
//
//	}
//	L.data[p - 1] = e;								//第p个元素对应数组中的L.data[p-1] 
//	L.length++;
//	cout << "插入成功" << endl;
//}
//
////删除元素
//int deleteElem(SqList& L)
//{
//	int p;
//	cout << "请输入要删除的元素位置" << endl;
//	cin >> p;
//	if (p<0 || p>L.length - 1)						//判断地址是否合法 
//	{
//		cout << "地址不合法" << endl;
//		return 0;
//	}
//	for (int j = p; j <= L.length; j++)
//	{
//		L.data[j - 1] = L.data[j];					//从p位置开始，后面的依次前移 
//	}
//	L.length--;
//	cout << "删除成功" << endl;
//
//}
//
//int main() {
//	int n, e;
//	int flag;
//	while (1)
//	{
//		cout << "1、创建顺序表" << endl;
//		cout << "2、输出顺序表" << endl;
//		cout << "3、查找元素" << endl;
//		cout << "4、插入元素" << endl;
//		cout << "5、删除元素" << endl;
//		cout << "6、退出" << endl;
//		cout << "请输入你的选择：";
//		cin >> flag;
//		switch (flag)
//		{
//		case 1:
//			cout << "请输入顺序表长度" << endl;
//			cin >> n;									//输入数组的长度n
//			SqList L;
//			InitList(L);							//顺序表的初始化
//			CreatList(L, n);							//顺序表传值
//			break;
//		case 2:
//			Print(L);								//打印顺序表
//		case 3:
//			getElem(L);								//查找相应位置元素
//		case 4:
//			insertElem(L);							//插入元素 
//			Print(L);								//再次打印顺序表
//			break;
//		case 5:
//			deleteElem(L);							//删除元素
//			Print(L);								//再次打印顺序表
//			break;
//		case 6:
//			system("pause");
//		default:
//			cout << "你输入的选项有误";
//			break;
//		}
//		
//	}
//	return 0;
//}

int main() {
	int max, e;
	int flag;
	cout << "请输入顺序表最大长度" << endl;
	cin >> max;									//输入数组的长度n
	arrList MyList(max);
	while (1)
	{
		cout << "1、顺序表传值" << endl;
		cout << "2、输出顺序表" << endl;
		cout << "3、查找元素" << endl;
		cout << "4、插入元素" << endl;
		cout << "5、删除元素" << endl;
		cout << "6、销毁顺序表" << endl;
		cout << "7、退出" << endl;
		cout << "请输入你的选择：";
		cin >> flag;
		switch (flag)
		{
		case 1:
			int n;
			cout << "请输入传入个数:";
			cin >> n;
			if (n > max)
			{
				cout << "illegal" << endl;
			}
			for (int i = 0; i < n; i++)
			{
				int j;
				cin >> j;
				MyList.append(j);
			}
			break;
		case 2:
			MyList.showList();								//打印顺序表
			break;
		case 3:
			int po, f;
			cout << "请输入要查找的元素：";
			cin >> f;
			MyList.find(f, po);								//查找相应位置元素
			break;
		case 4:
			int posi, value;
			cout << "请输入要插入的元素：";
			cin >> value;
			cout << "请输入要插入的位置：";
			cin >> posi;
			MyList.insert(posi, value);								//插入元素 
			MyList.showList();								//再次打印顺序表
			break;
		case 5:
			int p;
			cout << "请输入要删除的元素：";
			cin >> p;
			MyList.del(p);
			MyList.showList();								//再次打印顺序表
			break;
		case 6:
			MyList.~arrList();
			cout << "finished" << endl;
			MyList.showList();
			break;
		case 7:
			system("pause");
			
		default:
			cout << "你输入的选项有误";
			break;
		}
	}
	return 0;
}