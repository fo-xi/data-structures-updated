#pragma once

#include "Color.h"

struct RBTreeNode
{
	int Key;
	Color Color;
	RBTreeNode* Left;
	RBTreeNode* Right;
	RBTreeNode* Parent;
};