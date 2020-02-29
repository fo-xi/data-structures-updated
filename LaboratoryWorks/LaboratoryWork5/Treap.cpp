#include <iostream>
#include "Treap.h"
#include "InputOutput.h"

using namespace std;

void Treap::Split(TreapNode* treapNode, int key, TreapNode*& left, TreapNode*& right)
{
	if (treapNode == nullptr)
	{
		left = right = nullptr;
	}
	else if (treapNode->Key <= key)
	{
		Split(treapNode->Right, key, treapNode->Right, right);
		left = treapNode;
	}
	else if (treapNode->Key >= key)
	{
		Split(treapNode->Left, key, left, treapNode->Left);
		right = treapNode;
	}
}

TreapNode* Treap::Merge(TreapNode* left, TreapNode* right)
{
	if (left == nullptr || right == nullptr)
	{
		return left == nullptr ? right : left;
	}
	if (left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}
	else
	{
		right->Left = Merge(left, right->Left);
		return right;
	}
}

//Unoptimized algorithm
TreapNode* Treap::AddUsingUnoptimizedAlgorithm(int key)
{
	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(Root, key, left, right);
	//add - single element tree
	TreapNode* add = new TreapNode();
	add->Key = key;
	add->Priority = rand() % 100;
	return Merge(Merge(left, add), right);
}

//Unoptimized algorithm
TreapNode* Treap::RemoveUsingUnoptimizedAlgorithm(int key)
{
	TreapNode* left;
	TreapNode* temp;
	TreapNode* right;
	Split(Root, key - 1, left, right);
	Split(right, key, temp, right);
	delete temp;
	return Merge(left, right);
}

//Optimized algorithm
TreapNode* Treap::AddUsingOtimizedAlgorithm(TreapNode* treapNode, int key)
{
	TreapNode* temp = new TreapNode();
	temp->Key = key;
	temp->Priority = rand() % 100;
	if (treapNode == nullptr)
	{
		treapNode = temp;
	}
	else if (treapNode->Priority < temp->Priority)
	{
		Split(treapNode, temp->Key, temp->Left, temp->Right);
		treapNode = temp;
	}
	else if ((treapNode->Key == temp->Key) && (treapNode->Priority == temp->Priority))
	{
		return treapNode;
	}
	else
	{
		if (treapNode->Key > temp->Key)
		{
			treapNode->Right = AddUsingOtimizedAlgorithm(treapNode->Right, temp->Key);
		}
		else
		{
			treapNode->Left = AddUsingOtimizedAlgorithm(treapNode->Left, temp->Key);
		}
	}
	return treapNode;
}

//Optimized algorithm
TreapNode* Treap::RemoveUsingOtimizedAlgorithm(TreapNode* treapNode, int key)
{
	if (treapNode == nullptr)
	{
		return treapNode;
	}
	else if (treapNode->Key == key)
	{
		TreapNode* temp = treapNode;
		treapNode = Merge(treapNode->Left, treapNode->Right);
		delete temp;
	}
	else
	{
		if (treapNode->Key < key)
		{
			treapNode->Right = RemoveUsingOtimizedAlgorithm(treapNode->Right, key);
		}
		else
		{
			treapNode->Left = RemoveUsingOtimizedAlgorithm(treapNode->Left, key);
		}
	}

	return treapNode;
}

void Treap::SearchElement(int key, int& priority)
{
	TreapNode* temp = Root;
	while (temp != nullptr)
	{
		if (temp->Key == key)
		{
			priority = temp->Priority;
			ShowResult(priority);
		}
		if (temp->Key > key)
		{
			temp = temp->Left;
		}
		else
		{
			temp = temp->Right;
		}
	}
}

void Treap::DeleteTreap(TreapNode* treapNode)
{
	if (treapNode->Left)
	{
		DeleteTreap(treapNode->Left);
	}
	if (treapNode->Right)
	{
		DeleteTreap(treapNode->Right);
	}
	delete treapNode;
}