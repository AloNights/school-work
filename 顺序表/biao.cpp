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
			cout << "��ֵ��λ��Ϊ��" << po + 1 << endl;
			return;
		}
	}
	cout << "cannot find the value" << endl;
}
//#define MaxSize 100
//
////˳���Ľ��� 
//typedef struct {
//	int data[MaxSize];					// 	�洢�ռ�Ļ���ַ
//	int length;							//��ǰ���� 
//}SqList;
//
//
//// ˳���ĳ�ʼ��
//void InitList(SqList& L) {
//	L.length = 0;
//	cout << "˳����ʼ�����" << endl;
//}
//
//// ˳���ֵ 
//void CreatList(SqList& L, int n)
//{
//
//	cout << "�봫����ֵ" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> L.data[i];
//		L.length++;
//	}
//}
//
////��ӡ˳��� 
//int Print(SqList L)
//{
//	cout << "Ŀǰ˳���Ϊ��" << endl;
//	if (L.length == 0)
//	{
//		return 0;
//	}
//	for (int k = 0; k < L.length; k++)		//���˳��� 
//	{
//		cout << L.data[k] << "\t";
//	}
//	cout << endl;
//}
////����Ԫ��
//int getElem(SqList L)
//{
//	int p;
//	int e;
//	cout << "������Ҫ����Ԫ�ص�λ��" << endl;
//	cin >> p;
//	if (p<0 || p>L.length - 1)
//	{
//		return 0;
//	}
//	else
//	{
//		e = L.data[p - 1];							// ��p��Ԫ�ض�Ӧ�����е�L.data[p-1]
//		cout << "��Ҫ���ҵ�Ԫ��Ϊ��" << e << endl;
//	}
//}
//
////����Ԫ��
//int insertElem(SqList& L)
//{
//	int p, e, i;
//	cout << "������Ҫ�����λ�ü�Ԫ��" << endl;
//	cin >> p >> e;
//	if (p<0 || p>L.length || L.length == MaxSize)		//�ж�Ҫ�����λ���Ƿ�Ϸ������ж����Ա��Ƿ�ﵽ����� 
//	{
//		cout << "�����ַ���Ϸ�" << endl;
//		return 0;
//	}
//	for (i = L.length - 1; i >= p - 1; i--)
//	{
//		L.data[i + 1] = L.data[i];					//�Ӻ���ǰ�������Ԫ�غ��� 
//
//	}
//	L.data[p - 1] = e;								//��p��Ԫ�ض�Ӧ�����е�L.data[p-1] 
//	L.length++;
//	cout << "����ɹ�" << endl;
//}
//
////ɾ��Ԫ��
//int deleteElem(SqList& L)
//{
//	int p;
//	cout << "������Ҫɾ����Ԫ��λ��" << endl;
//	cin >> p;
//	if (p<0 || p>L.length - 1)						//�жϵ�ַ�Ƿ�Ϸ� 
//	{
//		cout << "��ַ���Ϸ�" << endl;
//		return 0;
//	}
//	for (int j = p; j <= L.length; j++)
//	{
//		L.data[j - 1] = L.data[j];					//��pλ�ÿ�ʼ�����������ǰ�� 
//	}
//	L.length--;
//	cout << "ɾ���ɹ�" << endl;
//
//}
//
//int main() {
//	int n, e;
//	int flag;
//	while (1)
//	{
//		cout << "1������˳���" << endl;
//		cout << "2�����˳���" << endl;
//		cout << "3������Ԫ��" << endl;
//		cout << "4������Ԫ��" << endl;
//		cout << "5��ɾ��Ԫ��" << endl;
//		cout << "6���˳�" << endl;
//		cout << "���������ѡ��";
//		cin >> flag;
//		switch (flag)
//		{
//		case 1:
//			cout << "������˳�����" << endl;
//			cin >> n;									//��������ĳ���n
//			SqList L;
//			InitList(L);							//˳���ĳ�ʼ��
//			CreatList(L, n);							//˳���ֵ
//			break;
//		case 2:
//			Print(L);								//��ӡ˳���
//		case 3:
//			getElem(L);								//������Ӧλ��Ԫ��
//		case 4:
//			insertElem(L);							//����Ԫ�� 
//			Print(L);								//�ٴδ�ӡ˳���
//			break;
//		case 5:
//			deleteElem(L);							//ɾ��Ԫ��
//			Print(L);								//�ٴδ�ӡ˳���
//			break;
//		case 6:
//			system("pause");
//		default:
//			cout << "�������ѡ������";
//			break;
//		}
//		
//	}
//	return 0;
//}

int main() {
	int max, e;
	int flag;
	cout << "������˳�����󳤶�" << endl;
	cin >> max;									//��������ĳ���n
	arrList MyList(max);
	while (1)
	{
		cout << "1��˳���ֵ" << endl;
		cout << "2�����˳���" << endl;
		cout << "3������Ԫ��" << endl;
		cout << "4������Ԫ��" << endl;
		cout << "5��ɾ��Ԫ��" << endl;
		cout << "6������˳���" << endl;
		cout << "7���˳�" << endl;
		cout << "���������ѡ��";
		cin >> flag;
		switch (flag)
		{
		case 1:
			int n;
			cout << "�����봫�����:";
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
			MyList.showList();								//��ӡ˳���
			break;
		case 3:
			int po, f;
			cout << "������Ҫ���ҵ�Ԫ�أ�";
			cin >> f;
			MyList.find(f, po);								//������Ӧλ��Ԫ��
			break;
		case 4:
			int posi, value;
			cout << "������Ҫ�����Ԫ�أ�";
			cin >> value;
			cout << "������Ҫ�����λ�ã�";
			cin >> posi;
			MyList.insert(posi, value);								//����Ԫ�� 
			MyList.showList();								//�ٴδ�ӡ˳���
			break;
		case 5:
			int p;
			cout << "������Ҫɾ����Ԫ�أ�";
			cin >> p;
			MyList.del(p);
			MyList.showList();								//�ٴδ�ӡ˳���
			break;
		case 6:
			MyList.~arrList();
			cout << "finished" << endl;
			MyList.showList();
			break;
		case 7:
			system("pause");
			
		default:
			cout << "�������ѡ������";
			break;
		}
	}
	return 0;
}