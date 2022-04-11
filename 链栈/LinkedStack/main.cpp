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
	cout << "请输入要匹配的括号:";
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
				cout << "第" << i << "个')'没有被匹配" << endl;
			}
			else
			{
				lstack.Pop(ch);
				cout << "成功匹配一对" << endl;
				i--;
			}
		}
	}
	if (!lstack.isEmpty())
		cout <<  i << "个'('不匹配";
	cout << endl;
	return 0;
}