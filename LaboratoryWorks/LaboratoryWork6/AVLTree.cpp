#include <iostream>
#include "AVLTree.h"

using namespace std;

unsigned char AVLTree::GetHeight(AVLTreeNode* avlTreeNode)
{
	return avlTreeNode ? avlTreeNode->Height : 0;
}

int AVLTree::GetBalanceFactor(AVLTreeNode* avlTreeNode)
{
	return GetHeight(avlTreeNode->Right) - GetHeight(avlTreeNode->Left);
}

void AVLTree::FixHeight(AVLTreeNode* avlTreeNode)
{
	unsigned char heightLeft = GetHeight(avlTreeNode->Left);
	unsigned char heightRight = GetHeight(avlTreeNode->Right);
	avlTreeNode->Height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

AVLTreeNode* AVLTree::RotateRight(AVLTreeNode* avlTreeNode)
{
	AVLTreeNode* temp = avlTreeNode->Left;
	avlTreeNode->Left = temp->Right;
	temp->Right = avlTreeNode;
	FixHeight(avlTreeNode);
	FixHeight(temp);
	return temp;
}

AVLTreeNode* AVLTree::RotateLeft(AVLTreeNode* avlTreeNode)
{
	AVLTreeNode* temp = avlTreeNode->Right;
	avlTreeNode->Right = temp->Left;
	temp->Left = avlTreeNode;
	FixHeight(avlTreeNode);
	FixHeight(temp);
	return temp;
}

AVLTreeNode* AVLTree::Balance(AVLTreeNode* avlTreeNode)
{
	FixHeight(avlTreeNode);
	if (GetBalanceFactor(avlTreeNode) == 2)
	{
		if (GetBalanceFactor(avlTreeNode->Right) < 0)
		{
			avlTreeNode->Right = RotateRight(avlTreeNode->Right);
		}
		return RotateLeft(avlTreeNode);
	}
	if (GetBalanceFactor(avlTreeNode) == -2)
	{
		if (GetBalanceFactor(avlTreeNode->Left) > 0)
		{
			avlTreeNode->Left = RotateLeft(avlTreeNode->Left);
		}
		return RotateRight(avlTreeNode);
	}
	return avlTreeNode;
}

AVLTreeNode* AVLTree::SearchMin(AVLTreeNode* avlTreeNode)
{
	if (avlTreeNode == nullptr)
	{
		return nullptr;
	}
	if (avlTreeNode->Left == nullptr)
	{
		return avlTreeNode;
	}
	return SearchMin(avlTreeNode->Left);
}

AVLTreeNode* AVLTree::RemoveMin(AVLTreeNode* avlTreeNode)
{
	if (!avlTreeNode->Left)
	{
		return avlTreeNode->Right;
	}
	avlTreeNode->Left = RemoveMin(avlTreeNode->Left);
	return Balance(avlTreeNode);
}

void AVLTree::DeleteAVLTree(AVLTreeNode* avlTreeNode)
{
	if (avlTreeNode->Left)
	{
		DeleteAVLTree(avlTreeNode->Left);
	}
	if (avlTreeNode->Right)
	{
		DeleteAVLTree(avlTreeNode->Right);
	}
	delete avlTreeNode;
}

AVLTreeNode* AVLTree::SearchElement(AVLTreeNode* avlTreeNode, int value)
{
	if (avlTreeNode == nullptr)
	{
		return nullptr;
	}
	if (avlTreeNode->Key == value)
	{
		return avlTreeNode;
	}
	if (avlTreeNode->Key > value)
	{
		return SearchElement(avlTreeNode->Left, value);
	}
	else
	{
		return SearchElement(avlTreeNode->Right, value);
	}
}

AVLTreeNode* AVLTree::AddElement(AVLTreeNode* avlTreeNode, int value)
{
	if (!avlTreeNode)
	{
		return new AVLTreeNode(value);
	}
	if (value < avlTreeNode->Key)
	{
		avlTreeNode->Left = AddElement(avlTreeNode->Left, value);
	}
	else if (value > avlTreeNode->Key)
	{
		avlTreeNode->Right = AddElement(avlTreeNode->Right, value);
	}
	else
	{
		return avlTreeNode;
	}
	return Balance(avlTreeNode);
}

AVLTreeNode* AVLTree::RemoveElement(AVLTreeNode* avlTreeNode, int value)
{
	if (!avlTreeNode)
	{
		return nullptr;
	}
	if (value < avlTreeNode->Key)
	{
		avlTreeNode->Left = RemoveElement(avlTreeNode->Left, value);
	}
	else if (value > avlTreeNode->Key)
	{
		avlTreeNode->Right = RemoveElement(avlTreeNode->Right, value);
	}
	else
	{
		AVLTreeNode* left = avlTreeNode->Left;
		AVLTreeNode* right = avlTreeNode->Right;
		delete avlTreeNode;
		if (!right)
		{
			return left;
		}
		AVLTreeNode* min = SearchMin(right);
		min->Right = RemoveMin(right);
		min->Left = left;
		return Balance(min);
	}
	return Balance(avlTreeNode);
}