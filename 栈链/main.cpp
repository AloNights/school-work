#include "linkedSatck.h"
#include <iostream>
#include<vector>

using namespace std;

int main()
{
	int i = 1;
	int value;
	LinkStack lstack;
	char ch;
	vector<char> pr;
	cout << "������Ҫƥ�������:";
	while ((ch = cin.get()) != '\n')
		pr.push_back(ch);
	for (char ch : pr)
	{
		if (ch == '(')
		{
			lstack.Push(ch);
		}
		else if (ch == ')')
		{
			++i;
			if (lstack.isEmpty())
			{
				cout << "��" << i << "��')'û�б�ƥ��" << endl;
			}
			else
			{
				lstack.Pop(ch);
				cout << "�ɹ�ƥ��һ��" << endl;
				i--;
			}
		}
	}
	if (!lstack.isEmpty())
		cout <<  i << "��'('��ƥ��";
	cout << endl;
	return 0;
}