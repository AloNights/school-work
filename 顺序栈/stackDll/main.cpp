#include "arrStack.h"
#include<iostream>

using namespace std;

int main()
{
	int sel = 0;
	int num;
	int m;
	cout << "������ջ���������";
	cin >> m;
	arrStack astack(m);
	while (1)
	{
		cout << "---------------------------" << endl;
		cout << "---------- 1.��ջ ---------" << endl;
		cout << "---------- 2.��ջ ---------" << endl;
		cout << "-------- 3.ջ��Ԫ�� -------" << endl;
		cout << "------ 4.����Ƿ��ջ -----" << endl;
		cout << "--------- 5.����ջ --------" << endl;
		cout << "------ 6.��ʾջ��Ԫ�� -----" << endl;
		cout << "---------- 7.�˳� ---------" << endl;
		cout << "---------------------------" << endl;
		cin >> sel;
		switch (sel)
		{
		case 1:
			cout << "���������Ԫ��:";
			cin >> num;
			astack.Push(num); break;
		case 2:
			int out;
			astack.Pop(out);
			cout << out << "�ѳ�ջ" << endl; break;
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