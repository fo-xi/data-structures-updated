#pragma once

#include <iostream>
#include "RBTreeNode.h"

using namespace std;

struct RBTree
{
	RBTreeNode* Root = nullptr;
	RBTreeNode* Nil;

	RBTreeNode* CreateNode();
	void RotateLeft(RBTreeNode*);
	void RotateRight(RBTreeNode*);
	void FixInsert(RBTreeNode*);
	void InsertElement(int);
	void FixDelete(RBTreeNode*);
	RBTreeNode* SearchMin(RBTreeNode*);
	void DeleteElement(RBTreeNode*);
	void RemoveElement(int);
	RBTreeNode* SearchElement(RBTreeNode*, int);
	void DeleteRBTree(RBTreeNode*);
};