#define DLL_IMPORT
#pragma comment(lib,"ListNodeDll.lib")
#include <iostream>
#include "../ListNodeDll/dll.h"

int main()
{
	List MyList;
	// ������
	MyList.ShowList();
	// β����ӽڵ�
	MyList.AddEndNode(1);
	MyList.AddEndNode(4);
	MyList.AddEndNode(3);
	MyList.InsertNode(6, 2);
	MyList.AddFrontNode(5);
	// ��ʾ��Ӻ������
	MyList.ShowList();
	MyList.ReverseShowList();
	MyList.Find(3);
	// ɾ���ڵ�
	MyList.DeleteNode(8);
	MyList.DeleteNode(4);
	MyList.ShowList();
	MyList.RemoveList();
	MyList.ShowList();

	List YourList(MyList);
	YourList.ShowList();

	return 0;
}