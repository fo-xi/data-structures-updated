#pragma once

#include <iostream>
#include "AVLTreeNode.h"

using namespace std;

struct AVLTree
{
	AVLTreeNode* Root = nullptr;

	unsigned char GetHeight(AVLTreeNode*);
	int GetBalanceFactor(AVLTreeNode*);
	void FixHeight(AVLTreeNode*);
	AVLTreeNode* RotateRight(AVLTreeNode*);
	AVLTreeNode* RotateLeft(AVLTreeNode*);
	AVLTreeNode* Balance(AVLTreeNode*);
	AVLTreeNode* SearchMin(AVLTreeNode*);
	AVLTreeNode* RemoveMin(AVLTreeNode*);
	void DeleteAVLTree(AVLTreeNode*);
	AVLTreeNode* SearchElement(AVLTreeNode*, int);
	AVLTreeNode* AddElement(AVLTreeNode*, int);
	AVLTreeNode* RemoveElement(AVLTreeNode*, int);
};