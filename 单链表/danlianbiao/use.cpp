#define DLL_IMPORT
#pragma comment(lib,"ListNodeDll.lib")
#include <iostream>
#include "../ListNodeDll/dll.h"

int main()
{
	List MyList;
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
	MyList.ReverseShowList();
	MyList.Find(3);
	// 删除节点
	MyList.DeleteNode(8);
	MyList.DeleteNode(4);
	MyList.ShowList();
	MyList.RemoveList();
	MyList.ShowList();

	List YourList(MyList);
	YourList.ShowList();

	return 0;
}