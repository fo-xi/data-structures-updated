#include <iostream>
#include "InputOutput.h"

using namespace std;

void OutputСycle(int level)
{
	for (int i = 0; i < level; i++)
	{
		cout << "   ";
	}
}

void ShowAVLTree(AVLTreeNode* avlTreeNode, int level)
{
	if (avlTreeNode)
	{
		ShowAVLTree(avlTreeNode->Right, level + 1);
		OutputСycle(level);
		cout << avlTreeNode->Key << endl;
		ShowAVLTree(avlTreeNode->Left, level + 1);
	}
}

void ShowRBTree(RBTreeNode* rbTreeNode, int level, RBTreeNode* Nil)
{
	if (rbTreeNode && rbTreeNode != Nil)
	{
		ShowRBTree(rbTreeNode->Right, level + 1, Nil);
		OutputСycle(level);
		cout << rbTreeNode->Key;
		if (rbTreeNode->Color == RED)
		{
			cout << " RED" << endl;
		}
		else
		{
			cout << " BLACK" << endl;
		}
		ShowRBTree(rbTreeNode->Left, level + 1, Nil);
	}
}

void ShowElementAVLTree(AVLTree* avlTree, int value)
{
	if (avlTree->Root == nullptr)
	{
		cout << "Is empty" << endl;
		return;
	}
	if (avlTree->SearchElement(avlTree->Root, value) == nullptr)
	{
		cout << "Not found!" << endl;
		return;
	}
	cout << "Item found!" << avlTree->SearchElement(avlTree->Root, value)->Key << endl;
}

void ShowElementRBTree(RBTree* rbTree, int value)
{
	if (rbTree->Root == nullptr)
	{
		cout << "Is empty" << endl;
		return;
	}
	if (rbTree->SearchElement(rbTree->Root, value) == nullptr)
	{
		cout << "Not found!" << endl;
		return;
	}
	cout << "Item found" << endl;
}