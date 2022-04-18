#include <iostream>
#include "tree.h"
#include <stdio.h>
#include <stack>
#include <queue>

#include <stdlib.h>
using namespace std;

void CreateTree(CSTree* T) {
	(*T) = NULL;
	ElemType Felem;
	ElemType Selem;
	CSNode* r = NULL;
	CSNode* p = NULL;
	queue<CSNode*> Q;
	for (scanf("%c%c", &Felem, &Selem); Selem != '#'; scanf("%c%c", &Felem, &Selem)) {
		CSNode* node;
		node = (CSNode*)malloc(sizeof(CSNode));
		node->data = Selem;
		node->firstchild = NULL;
		node->nextsibling = NULL;
		Q.push(node);
		if (Felem == '#') {
			(*T) = node;
			r = node;
		}
		else {
			while (Q.front()->data != Felem) {
				Q.pop();
			}
			p = Q.front();
			if (!(p->firstchild)) {
				p->firstchild = node;
				r = node;
			}
			else {
				r->nextsibling = node;
				r = node;
			}
		}
	}
}

void DestroyTree(CSTree* T) {
	if (*T) {
		DestroyTree(&((*T)->firstchild));
		DestroyTree(&((*T)->nextsibling));
		free(*T);
		(*T) = NULL;
	}
}

unsigned int TreeDepth(CSTree T) {
	if (T) {
		return (1 + TreeDepth(T->firstchild)) > TreeDepth(T->nextsibling) ? (1 + TreeDepth(T->firstchild)) : TreeDepth(T->nextsibling);
	}
	return 0;
}

void AllPath(CSTree T, stack<ElemType>* S1) {
	//stack<ElemType> S1;

	while (T != NULL) {
		S1->push(T->data);
		if (T->firstchild == NULL) {
			stack<ElemType> S2;
			S2 = (*S1);
			while (!S2.empty()) {
				printf("%c\n", S2.top());
				S2.pop();
			}
		}
		else {
			AllPath(T->firstchild, S1);
		}
		S1->pop();
		T = T->nextsibling;
	}
}

void PrintTree(CSTree T) {
	if (T) {
		cout << T->data << endl;
		PrintTree(T->firstchild);
		PrintTree(T->nextsibling);
	}
}
