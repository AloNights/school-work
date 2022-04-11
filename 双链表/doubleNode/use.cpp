#define DLL_IMPORT
#pragma comment(lib,"doubleDll.lib")
#include <iostream>
#include "../doubleDll/doubledll.h"

using namespace std;

int main()
{
	DoubleLink MyList;
	// 空链表
	MyList.ShowList();
	// 尾部添加节点
	MyList.AddEndNode(1);
	MyList.AddEndNode(4);
	MyList.AddEndNode(3);
	MyList.InsertNode(6, 2);
	MyList.AddFrontNode(5);
	// 显示添加后的链表
	MyList.ShowList();
	int value=MyList.Find(2);
	cout << value << endl;
	cout << endl;
	cout << MyList.getlength()<<endl;
	cout << endl;
	// 删除节点
	MyList.DeleteNode(3);
	MyList.ShowList();
	MyList.RemoveList();
	MyList.ShowList();

	DoubleLink YourList(MyList);
	
}