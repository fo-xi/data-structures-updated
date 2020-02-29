#pragma once

#include <iostream>
#include "AVLTree.h"
#include "RBTree.h"
#include "..\Common\ReadNumber.h"

void OutputСycle(int);
void ShowAVLTree(AVLTreeNode*, int);
void ShowRBTree(RBTreeNode*, int, RBTreeNode*);
void ShowElementAVLTree(AVLTree*, int);
void ShowElementRBTree(RBTree*, int);