#pragma once

#include <iostream>
#include "TreapNode.h"

using namespace std;

struct Treap
{
	TreapNode* Root = nullptr;

	void Split(TreapNode*, int, TreapNode*&, TreapNode*&);
	TreapNode* Merge(TreapNode*, TreapNode*);
	TreapNode* AddUsingUnoptimizedAlgorithm(int);
	TreapNode* RemoveUsingUnoptimizedAlgorithm(int);
	TreapNode* AddUsingOtimizedAlgorithm(TreapNode*, int);
	TreapNode* RemoveUsingOtimizedAlgorithm(TreapNode*, int);
	void SearchElement(int, int&);
	void DeleteTreap(TreapNode*);
};