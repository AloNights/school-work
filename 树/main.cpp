#include <iostream>
#include "tree.h"
using namespace std;
int main() {
	CSTree T;
	CreateTree(&T);
	//cout << T->nextsibling->data << endl;
	//PrintTree(T);
	stack<ElemType> s;
	AllPath(T, &s);
	/*while (!s.empty()) {
		cout << s.top()	<< endl;
		s.pop();
	}*/
	cout << TreeDepth(T) << endl;
	DestroyTree(&T);
	if (!T) {
		cout << "delete successfully" << endl;
	}
	return 0;
}
