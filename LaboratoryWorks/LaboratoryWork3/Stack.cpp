#include <iostream>
#include "Stack.h"
#include "InputOutput.h"

void Stack::CreateStack()
{
	Capacity = bufferSize;
	Buffer = new int[Capacity];
	Top = -1;
	Length = 0;
}

void Stack::ResizeStack()
{
	if (Top != -1)
	{
		Capacity += bufferSize;
		int* newArray = new int[Capacity];
		for (int i = 0; i < Length; i++)
		{
			newArray[i] = Buffer[i];
		}
		delete[] Buffer;
		Buffer = newArray;
	}
	else
	{
		return;
	}
}

void Stack::Push(int value)
{
	if (Top == -1)
	{
		CreateStack();
	}

	if (Length < Capacity)
	{
		Top++;
		Buffer[Top] = value;
		Length++;
	}
	else
	{
		return;
	}
}

int Stack::Pop()
{
	if (Top == -1)
	{
		return -1;
	}
	else
	{
		int temp = Buffer[Top--];
		Length--;
		return temp;
	}
}

void Stack::DeleteStack()
{
	if (!(Top == -1))
	{
		delete[] Buffer;
		Top = -1;
		Capacity = 0;
		Length = 0;
	}
}