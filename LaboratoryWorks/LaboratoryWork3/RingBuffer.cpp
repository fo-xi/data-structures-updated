#include <iostream>
#include "RingBuffer.h"
#include "InputOutput.h"

void RingBuffer::CreateRingBuffer()
{
	Capacity = ringBufferSize;
	Array = new int[Capacity];
	WritePointer = -1;
	ReadPointer = -1;
	Length = 0;
}

void RingBuffer::ResizeRingBuffer()
{
	int* newArray = new int[Length];
	for (int i = 0; i < Length; i++)
	{
		newArray[i] = Array[(WritePointer + i) % Capacity];
	}
	delete[] Array;

	Capacity += ringBufferSize;
	Array = new int[Capacity];
	for (int i = 0; i < Length; i++)
	{
		Array[i] = newArray[i];
		ReadPointer = i;
	}
	WritePointer = 0;
	delete[] newArray;
}

bool RingBuffer::GetElement(int& result)
{
	if (IsEmpty(WritePointer, ReadPointer))
	{
		return false;
	}
	result = Array[WritePointer];
	if (WritePointer == ReadPointer)
	{
		WritePointer = -1;
		ReadPointer = -1;
	}
	else
	{
		WritePointer = (WritePointer + 1) % Capacity;
	}
	Length--;
	return true;
}

void RingBuffer::AddElement(int value, int& result)
{
	if (Length == 0)
	{
		CreateRingBuffer();
	}
	if ((ReadPointer + 1) % Capacity == WritePointer)
	{
		GetElement(result);
	}
	if (WritePointer == -1)
	{
		WritePointer = 0;
	}
	ReadPointer = (ReadPointer + 1) % Capacity;
	Array[ReadPointer] = value;
	Length++;
}

void RingBuffer::DeleteRingBuffer()
{
	if (!((WritePointer = -1) && (ReadPointer = -1)))
	{
		delete[] Array;
		WritePointer = -1;
		ReadPointer = -1;
		Length = 0;
		Capacity = 0;
	}
}