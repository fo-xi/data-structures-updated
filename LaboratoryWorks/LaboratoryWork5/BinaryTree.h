#pragma once

#include <iostream>
#include "BinaryTreeNode.h"

using namespace std;

struct BinaryTree
{
	BinaryTreeNode* Root = nullptr;

	BinaryTreeNode* AddElement(BinaryTreeNode*, int);
	BinaryTreeNode* SearchMin(BinaryTreeNode*);
	BinaryTreeNode* SearchMax(BinaryTreeNode*);
	BinaryTreeNode* SearchElement(BinaryTreeNode*, int);
	BinaryTreeNode* RemoveElement(BinaryTreeNode*, int);
	void DeleteBinaryTree(BinaryTreeNode*);
};