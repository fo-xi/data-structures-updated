#include <iostream>
#include "InputOutput.h"

using namespace std;

void Cycle(int level)
{
	for (int i = 0; i < level; i++)
	{
		cout << "   ";
	}
}

void ShowBinaryTree(BinaryTreeNode* binaryTreeNode, int level)
{
	if (binaryTreeNode)
	{
		ShowBinaryTree(binaryTreeNode->Right, level + 1);
		Cycle(level);
		cout << binaryTreeNode->Data << endl;
		ShowBinaryTree(binaryTreeNode->Left, level + 1);
	}
}

void ShowTreap(TreapNode* treapNode, int level)
{
	if (treapNode)
	{
		ShowTreap(treapNode->Right, level + 1);
		Cycle(level);
		cout << "(" << treapNode->Key << "; " << treapNode->Priority << ")" << endl;
		ShowTreap(treapNode->Left, level + 1);
	}
}

void ShowElement(BinaryTree* binaryTree, int value)
{
	if (binaryTree->Root == nullptr)
	{
		cout << "Is empty" << endl;
		return;
	}
	if (binaryTree->SearchElement(binaryTree->Root, value) == nullptr)
	{
		cout << "Not found!" << endl;
		return;
	}
	cout << "Value found! ->\t"
		<< binaryTree->SearchElement(binaryTree->Root, value)->Data << endl;
}

void ShowResult(int& priority)
{
	cout << "Priority->\t" << priority << endl;
}