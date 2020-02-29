#include <iostream>
#include "RBTree.h"

using namespace std;

RBTreeNode* RBTree::CreateNode()
{
	RBTreeNode* node = new RBTreeNode();
	node->Left = node->Right = node->Parent = Nil;
	return node;
}

void RBTree::RotateLeft(RBTreeNode* rbTreeNode)
{
	RBTreeNode* temp = rbTreeNode->Right;
	rbTreeNode->Right = temp->Left;
	if (temp->Left != Nil)
	{
		temp->Left->Parent = rbTreeNode;
	}
	temp->Parent = rbTreeNode->Parent;
	if (!rbTreeNode->Parent)
	{
		Root = temp;
	}
	else if (rbTreeNode == rbTreeNode->Parent->Left)
	{
		rbTreeNode->Parent->Left = temp;
	}
	else
	{
		rbTreeNode->Parent->Right = temp;
	}
	temp->Left = rbTreeNode;
	rbTreeNode->Parent = temp;
}

void RBTree::RotateRight(RBTreeNode* rbTreeNode)
{
	RBTreeNode* temp = rbTreeNode->Left;
	rbTreeNode->Left = temp->Right;
	if (temp->Right != Nil)
	{
		temp->Right->Parent = rbTreeNode;
	}
	temp->Parent = rbTreeNode->Parent;
	if (rbTreeNode->Parent == Nil)
	{
		Root = temp;
	}
	else if (rbTreeNode == rbTreeNode->Parent->Right)
	{
		rbTreeNode->Parent->Right = temp;
	}
	else
	{
		rbTreeNode->Parent->Left = temp;
	}
	temp->Right = rbTreeNode;
	rbTreeNode->Parent = temp;
}

void RBTree::FixInsert(RBTreeNode* rbTreeNode)
{
	if (Root == rbTreeNode)
	{
		rbTreeNode->Color = BLACK;
		return;
	}
	while ((rbTreeNode->Parent) && (rbTreeNode->Parent->Color == RED))
	{
		RBTreeNode* grandfather = rbTreeNode->Parent->Parent;
		if (grandfather->Left == rbTreeNode->Parent)
		{
			if (grandfather->Right != Nil)
			{
				RBTreeNode* uncle = grandfather->Right;
				/*Case 1:
				The uncle of this knot is red.
				We repaint “father”and “uncle” in black, and “grandfather” - in red.*/
				if (uncle->Color == RED)
				{
					rbTreeNode->Parent->Color = BLACK;
					uncle->Color = BLACK;
					grandfather->Color = RED;
					rbTreeNode = grandfather;
				}
			}
			else
			{
				/*Case 2:
				The uncle of this knot is black.
				We carry out a turn.
				If the added node was a right descendant, then you must first perform a left rotation*/
				if (rbTreeNode->Parent->Right == rbTreeNode)
				{
					rbTreeNode = rbTreeNode->Parent;
					RotateLeft(rbTreeNode);
				}
				rbTreeNode->Parent->Color = BLACK;
				grandfather->Color = RED;
				RotateRight(grandfather);
			}
		}
		else
		{
			if (grandfather->Left != Nil)
			{
				RBTreeNode* uncle = grandfather->Left;
				if (uncle->Color == RED)
				{
					rbTreeNode->Parent->Color = BLACK;
					uncle->Color = BLACK;
					grandfather->Color = RED;
					rbTreeNode = grandfather;
				}
			}
			else
			{
				if (rbTreeNode->Parent->Left == rbTreeNode)
				{
					rbTreeNode = rbTreeNode->Parent;
					RotateRight(rbTreeNode);
				}
				rbTreeNode->Parent->Color = BLACK;
				grandfather->Color = RED;
				RotateLeft(grandfather);
			}
		}
		Root->Color = BLACK;
	}
}

void RBTree::InsertElement(int key)
{
	RBTreeNode* temp;
	RBTreeNode* parent;
	RBTreeNode* insertableItem;
	temp = Root;
	parent = nullptr;
	while ((temp != Nil) && (temp))
	{
		if (key == temp->Key)
		{
			return;
		}
		parent = temp;
		if (key < temp->Key)
		{
			temp = temp->Left;
		}
		else
		{
			temp = temp->Right;
		}
	}
	insertableItem = CreateNode();
	insertableItem->Parent = parent;
	insertableItem->Color = RED;
	insertableItem->Key = key;
	if (parent)
	{
		if (key < parent->Key)
		{
			parent->Left = insertableItem;
		}
		else
		{
			parent->Right = insertableItem;
		}
	}
	else
	{
		Root = insertableItem;
	}
	FixInsert(insertableItem);
}

void RBTree::FixDelete(RBTreeNode* rbTreeNode)
{
	while (rbTreeNode != Root && rbTreeNode->Color == BLACK)
	{
		if (rbTreeNode == rbTreeNode->Parent->Left)
		{
			RBTreeNode* brother = rbTreeNode->Parent->Right;
			/*Case 1:
			The brother of this child is red.
			We maket rotatation around the rib between the father and brother.
			We paint it in black, and his father in red.*/
			if (brother->Color == RED)
			{
				brother->Color = BLACK;
				rbTreeNode->Parent->Color = RED;
				RotateLeft(rbTreeNode->Parent);
				brother = rbTreeNode->Parent->Right;
			}
			/*Case 2:
			Both children have black brothers.
			We paint the brother in red and look further at the father of the peak.*/
			if (brother->Left->Color == BLACK && brother->Right->Color == BLACK)
			{
				brother->Color = RED;
				rbTreeNode = rbTreeNode->Parent;
			}
			else
			{
				/*Case 3:
				If the brother has the right child blackand the left red.
				We repaint the brotherand his left sonand make a rotation.*/
				if (brother->Right->Color == BLACK)
				{
					brother->Left->Color = BLACK;
					brother->Color = RED;
					RotateRight(brother);
					brother = rbTreeNode->Parent->Right;
				}
				/*Case 4:
				If the brother of the right child is red.
				We repaint the brother in the color of the father, his child and father - in black, do the rotation.*/
				brother->Color = rbTreeNode->Parent->Color;
				rbTreeNode->Parent->Color = BLACK;
				brother->Right->Color = BLACK;
				RotateLeft(rbTreeNode->Parent);
				rbTreeNode = Root;
			}
		}
		else
		{
			RBTreeNode* brother = rbTreeNode->Parent->Left;
			if (brother->Color == RED)
			{
				brother->Color = BLACK;
				rbTreeNode->Parent->Color = RED;
				RotateRight(rbTreeNode->Parent);
				brother = rbTreeNode->Parent->Left;
			}
			if (brother->Right->Color == BLACK && brother->Left->Color == BLACK)
			{
				brother->Color = RED;
				rbTreeNode = rbTreeNode->Parent;
			}
			else
			{
				if (brother->Left->Color == BLACK)
				{
					brother->Right->Color = BLACK;
					brother->Color = RED;
					RotateLeft(brother);
					brother = rbTreeNode->Parent->Left;
				}
				brother->Color = rbTreeNode->Parent->Color;
				rbTreeNode->Parent->Color = BLACK;
				brother->Left->Color = BLACK;
				RotateRight(rbTreeNode->Parent);
				rbTreeNode = Root;
			}
		}
	}
	rbTreeNode->Color = BLACK;
}

RBTreeNode* RBTree::SearchMin(RBTreeNode* rbTreeNode)
{
	if (rbTreeNode == Nil)
	{
		return Nil;
	}
	if (rbTreeNode->Left == Nil)
	{
		return rbTreeNode;
	}
	return SearchMin(rbTreeNode->Left);
}

void RBTree::DeleteElement(RBTreeNode* rbTreeNode)
{
	RBTreeNode* temp;
	RBTreeNode* deleteElement;

	if (!rbTreeNode)
	{
		return;
	}

	if (rbTreeNode->Left == Nil || rbTreeNode->Right == Nil)
	{
		deleteElement = rbTreeNode;
	}
	else
	{
		deleteElement = SearchMin(rbTreeNode->Right);
	}

	if (deleteElement->Left != Nil)
	{
		temp = deleteElement->Left;
	}
	else
	{
		temp = deleteElement->Right;
	}
	if (temp)
	{
		temp->Parent = deleteElement->Parent;
	}
	if (deleteElement->Parent)
	{
		if (deleteElement == deleteElement->Parent->Left)
		{
			deleteElement->Parent->Left = temp;
		}
		else
		{
			deleteElement->Parent->Right = temp;
		}
	}
	else
	{
		Root = temp;
	}
	if (deleteElement != rbTreeNode)
	{
		rbTreeNode->Key = deleteElement->Key;
	}
	if (deleteElement->Color == BLACK)
	{
		FixDelete(temp);
	}
	delete deleteElement;
}

void RBTree::RemoveElement(int key)
{
	RBTreeNode* element = SearchElement(Root, key);
	if (element == Nil)
	{
		return;
	}
	DeleteElement(element);
}

RBTreeNode* RBTree::SearchElement(RBTreeNode* rbTreeNode, int key)
{
	if (rbTreeNode == Nil)
	{
		return Nil;
	}
	if (rbTreeNode->Key == key)
	{
		return rbTreeNode;
	}
	if (rbTreeNode->Key > key)
	{
		return SearchElement(rbTreeNode->Left, key);
	}
	else
	{
		return SearchElement(rbTreeNode->Right, key);
	}
}

void RBTree::DeleteRBTree(RBTreeNode* rbTreeNode)
{
	if (rbTreeNode->Left != Nil)
	{
		DeleteRBTree(rbTreeNode->Left);
	}
	if (rbTreeNode->Right != Nil)
	{
		DeleteRBTree(rbTreeNode->Right);
	}
	delete rbTreeNode;
}