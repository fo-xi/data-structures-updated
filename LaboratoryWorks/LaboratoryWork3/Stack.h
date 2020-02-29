#pragma once

const int bufferSize = 4;

struct Stack
{
	int* Buffer;
	int Top = -1;
	int Capacity;
	int Length;

	void CreateStack();
	void ResizeStack();
	void Push(int);
	int Pop();
	void DeleteStack();
};