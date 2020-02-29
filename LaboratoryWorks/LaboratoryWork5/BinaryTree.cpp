#include <iostream>
#include "BinaryTree.h"

using namespace std;

BinaryTreeNode* BinaryTree::AddElement(BinaryTreeNode* binaryTreeNode, int value)
{
	BinaryTreeNode* temp = new BinaryTreeNode();
	temp->Data = value;
	if (binaryTreeNode == nullptr)
	{
		binaryTreeNode = temp;
	}
	else if (binaryTreeNode->Data == temp->Data)
	{
		return binaryTreeNode;
	}
	else
	{
		if (binaryTreeNode->Data < temp->Data)
		{
			binaryTreeNode->Right = AddElement(binaryTreeNode->Right, temp->Data);
		}
		else
		{
			binaryTreeNode->Left = AddElement(binaryTreeNode->Left, temp->Data);
		}
	}
	return binaryTreeNode;
}

BinaryTreeNode* BinaryTree::SearchMin(BinaryTreeNode* binaryTreeNode)
{
	if (binaryTreeNode == nullptr)
	{
		return nullptr;
	}
	if (binaryTreeNode->Left == nullptr)
	{
		return binaryTreeNode;
	}
	return SearchMin(binaryTreeNode->Left);
}

BinaryTreeNode* BinaryTree::SearchMax(BinaryTreeNode* binaryTreeNode)
{
	if (binaryTreeNode == nullptr)
	{
		return nullptr;
	}
	if (binaryTreeNode->Right == nullptr)
	{
		return binaryTreeNode;
	}
	return SearchMax(binaryTreeNode->Right);
}

BinaryTreeNode* BinaryTree::SearchElement(BinaryTreeNode* binaryTreeNode, int value)
{
	if (binaryTreeNode == nullptr)
	{
		return nullptr;
	}
	if (binaryTreeNode->Data == value)
	{
		return binaryTreeNode;
	}
	if (binaryTreeNode->Data > value)
	{
		return SearchElement(binaryTreeNode->Left, value);
	}
	else
	{
		return SearchElement(binaryTreeNode->Right, value);
	}
}

BinaryTreeNode* BinaryTree::RemoveElement(BinaryTreeNode* binaryTreeNode, int value)
{
	if (binaryTreeNode == nullptr)
	{
		return binaryTreeNode;
	}
	if (binaryTreeNode->Data > value)
	{
		binaryTreeNode->Left = RemoveElement(binaryTreeNode->Left, value);
	}
	else if (binaryTreeNode->Data < value)
	{
		binaryTreeNode->Right = RemoveElement(binaryTreeNode->Right, value);
	}
	else
	{
		if (binaryTreeNode->Right == nullptr && binaryTreeNode->Left == nullptr)
		{
			binaryTreeNode = nullptr;
		}
		else if (binaryTreeNode->Right == nullptr)
		{
			BinaryTreeNode* temp = binaryTreeNode;
			binaryTreeNode = binaryTreeNode->Left;
			delete temp;
		}
		else if (binaryTreeNode->Left == nullptr)
		{
			BinaryTreeNode* temp = binaryTreeNode;
			binaryTreeNode = binaryTreeNode->Right;
			delete temp;
		}
		else
		{
			BinaryTreeNode* temp = SearchMin(binaryTreeNode->Right);
			binaryTreeNode->Data = temp->Data;
			binaryTreeNode->Right = RemoveElement(binaryTreeNode->Right, temp->Data);
		}
	}
	return binaryTreeNode;
}

void BinaryTree::DeleteBinaryTree(BinaryTreeNode* binaryTreeNode)
{
	if (binaryTreeNode->Left)
	{
		DeleteBinaryTree(binaryTreeNode->Left);
	}
	if (binaryTreeNode->Right)
	{
		DeleteBinaryTree(binaryTreeNode->Right);
	}
	delete binaryTreeNode;
}