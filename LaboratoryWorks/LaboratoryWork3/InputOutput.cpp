#include "InputOutput.h"
#include <iostream>

using namespace std;

void ShowStack(Stack* stack)
{
	system("cls");

	if (stack->Top == -1)
	{
		cout << "Stack is empty";
		return;
	}
	else
	{
		cout << "Stack:" << endl;

		for (int i = 0; i <= stack->Top; i++)
		{
			cout << stack->Buffer[i] << "\t";
		}
	}
}

void ShowQueue(Stack* stack)
{
	system("cls");

	if (stack->Top == -1)
	{
		cout << "Is empty" << endl;
		return;
	}
	else
	{
		cout << "Queue" << endl;

		for (int i = 0; i <= stack->Top; i++)
		{
			cout << stack->Buffer[i] << "\t";
		}
	}
}

bool IsEmpty(int head, int tail)
{
	if (head == -1 && tail == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ShowRingBuffer(RingBuffer* ring)
{
	system("cls");

	if (IsEmpty(ring->WritePointer, ring->ReadPointer))
	{
		cout << "Is empty" << endl;
	}
	else
	{
		cout << "Buffer" << endl;;

		int temp = ring->WritePointer;
		if (ring->WritePointer > ring->ReadPointer)
		{
			for (int i = temp; i < ring->Capacity; i++)
			{
				cout << ring->Array[i] << "\t";
			}
			temp = 0;
		}
		for (int i = temp; i <= ring->ReadPointer; i++)
		{
			cout << ring->Array[i] << "\t";
		}
	}
}

void FreePlace(int capacity, int length)
{
	cout << "Free ->\t" << capacity - length << endl;
}

void UsedPlace(int length)
{
	cout << "UsedPlace ->\t" << length << endl;
}

void ShowQueueRingBuffer(QueueRingBuffer* queue)
{
	system("cls");

	if (IsEmpty(queue->WritePointer, queue->ReadPointer))
	{
		cout << "Is empty" << endl;
	}
	else
	{
		cout << "Queue" << endl;;
		int temp = queue->WritePointer;
		if (queue->WritePointer > queue->ReadPointer)
		{
			for (int i = temp; i < queue->Capacity; i++)
			{
				cout << queue->Queue[i] << "\t";
			}
			temp = 0;
		}
		for (int i = temp; i <= queue->ReadPointer; i++)
		{
			cout << queue->Queue[i] << "\t";
		}
	}
}