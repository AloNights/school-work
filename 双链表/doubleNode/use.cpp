#define DLL_IMPORT
#pragma comment(lib,"doubleDll.lib")
#include <iostream>
#include "../doubleDll/doubledll.h"

using namespace std;

int main()
{
	DoubleLink MyList;
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
	int value=MyList.Find(2);
	cout << value << endl;
	cout << endl;
	cout << MyList.getlength()<<endl;
	cout << endl;
	// ɾ���ڵ�
	MyList.DeleteNode(3);
	MyList.ShowList();
	MyList.RemoveList();
	MyList.ShowList();

	DoubleLink YourList(MyList);
	
}