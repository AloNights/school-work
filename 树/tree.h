#pragma once
#ifndef _TREE_H_
#define _TREE_H_
//#include <stdbool.h>
#include <iostream>
#include <stack>
using namespace std;

typedef char ElemType;

typedef struct CSNode {
	ElemType data;
	struct CSNode* firstchild, * nextsibling;
}CSNode, * CSTree;

void CreateTree(CSTree* T);

void DestroyTree(CSTree* T);

unsigned int TreeDepth(CSTree T);

void AllPath(CSTree T, stack<ElemType>* S1);

void PrintTree(CSTree T);

#endif
