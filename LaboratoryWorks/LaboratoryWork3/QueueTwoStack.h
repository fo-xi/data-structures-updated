#pragma once

#include"Stack.h"

const int queueSize = 4;

struct TwoStack
{
	Stack* MainStack;
	Stack* SecondaryStack;

	void CreateStack(Stack*);
	void ResizeStack(Stack*);
	void PushMainStack(Stack*, int);
	void PushSecondaryStack(Stack*, int);
	int PopStack(Stack*);
	void Enqueue(Stack*, int);
	void Dequeue(Stack*, Stack*);
	void DeleteQueue(Stack*);
};