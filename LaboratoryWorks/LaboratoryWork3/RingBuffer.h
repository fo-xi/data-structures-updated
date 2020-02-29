#pragma once

const int ringBufferSize = 4;

struct RingBuffer
{
	int* Array;
	int WritePointer;
	int ReadPointer;
	int Capacity;
	int Length;

	void CreateRingBuffer();
	void ResizeRingBuffer();
	bool GetElement(int&);
	void AddElement(int, int&);
	void DeleteRingBuffer();
};