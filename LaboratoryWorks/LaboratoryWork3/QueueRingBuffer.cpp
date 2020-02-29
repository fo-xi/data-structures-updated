#include <iostream>
#include "InputOutput.h"
#include "QueueRingBuffer.h"

void QueueRingBuffer::CreateQueueRingBuffer()
{
	Capacity = queueRingBufferSize;
	Queue = new int[Capacity];
	WritePointer = -1;
	ReadPointer = -1;
	Length = 0;
}

void QueueRingBuffer::ResizeQueueRingBuffer()
{
	int* newArray = new int[Length];
	for (int i = 0; i < Length; i++)
	{
		newArray[i] = Queue[(WritePointer + i) % Capacity];
	}
	delete[] Queue;

	Capacity += queueRingBufferSize;
	Queue = new int[Capacity];
	for (int i = 0; i < Length; i++)
	{
		Queue[i] = newArray[i];
		ReadPointer = i;
	}
	WritePointer = 0;
	delete[] newArray;
}

void QueueRingBuffer::Dequeue()
{
	if (IsEmpty(WritePointer, ReadPointer))
	{
		return;
	}
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
}

void QueueRingBuffer::Enqueue(int value)
{
	if (Length == 0)
	{
		CreateQueueRingBuffer();
	}
	if ((ReadPointer + 1) % Capacity == WritePointer)
	{
		return;
	}
	if (WritePointer == -1)
	{
		WritePointer = 0;
	}
	ReadPointer = (ReadPointer + 1) % Capacity;
	Queue[ReadPointer] = value;
	Length++;

}

void QueueRingBuffer::DeleteQueueRingBuffer()
{
	if (!((WritePointer = -1) && (ReadPointer = -1)))
	{
		delete[] Queue;
		WritePointer = -1;
		ReadPointer = -1;
		Length = 0;
		Capacity = 0;
	}
}