#pragma once

const int queueRingBufferSize = 4;

struct QueueRingBuffer
{
	int* Queue;
	int WritePointer;
	int ReadPointer;
	int Capacity;
	int Length;

	void CreateQueueRingBuffer();
	void ResizeQueueRingBuffer();
	void Dequeue();
	void Enqueue(int);
	void DeleteQueueRingBuffer();
};