#pragma once

struct AVLTreeNode
{
	int Key;
	unsigned char Height;
	AVLTreeNode* Left;
	AVLTreeNode* Right;

	AVLTreeNode(int key)
	{
		Key = key;
		Left = Right = 0;
		Height = 1;
	}
};