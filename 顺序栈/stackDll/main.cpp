#include "arrStack.h"
#include<iostream>

using namespace std;

int main()
{
	int sel = 0;
	int num;
	int m;
	cout << "请输入栈最大容量：";
	cin >> m;
	arrStack astack(m);
	while (1)
	{
		cout << "---------------------------" << endl;
		cout << "---------- 1.进栈 ---------" << endl;
		cout << "---------- 2.出栈 ---------" << endl;
		cout << "-------- 3.栈顶元素 -------" << endl;
		cout << "------ 4.检查是否空栈 -----" << endl;
		cout << "--------- 5.销毁栈 --------" << endl;
		cout << "------ 6.显示栈内元素 -----" << endl;
		cout << "---------- 7.退出 ---------" << endl;
		cout << "---------------------------" << endl;
		cin >> sel;
		switch (sel)
		{
		case 1:
			cout << "请输入插入元素:";
			cin >> num;
			astack.Push(num); break;
		case 2:
			int out;
			astack.Pop(out);
			cout << out << "已出栈" << endl; break;
		case 3:
			cout << astack.Top(); break;
		case 4:
			cout << astack.isEmpty(); break;
		case 5:
			astack.~arrStack(); break;
		case 6:
			astack.showstack(); break;
		case 7:return 0;
		default:break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}