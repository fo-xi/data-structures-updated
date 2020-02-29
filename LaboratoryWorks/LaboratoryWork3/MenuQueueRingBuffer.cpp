#include <iostream>
#include "InputOutput.h"
#include "MenuQueueRingBuffer.h"
#include "QueueRingBuffer.h"

using namespace std;

void MenuQueueRingBuffer()
{
	setlocale(LC_ALL, "Rus");

	QueueRingBuffer* queue = new QueueRingBuffer();

	bool isEnd = true;

	queue->CreateQueueRingBuffer();

	while (isEnd)
	{
		system("cls");
		ShowQueueRingBuffer(queue);
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Add value to queue" << endl;
		cout << "2. Extract value from queue" << endl;
		cout << "3. Delete queue" << endl;
		cout << "4. Resize" << endl;
		cout << "5. Exit" << endl;

		cout << endl;
		cout << "SELECT AN ACTION :\t";

		switch (ReadNumber())
		{
			case 1:
			{
				cout << "Value ->\t";
				int value = ReadNumber();;
				queue->Enqueue(value);
				break;
			}
			case 2:
			{
				queue->Dequeue();
				break;
			}
			case 3:
			{
				queue->DeleteQueueRingBuffer();
				break;
			}
			case 4:
			{
				queue->ResizeQueueRingBuffer();
				break;
			}
			case 5:
			{
				isEnd = false;
				break;
			}
		default:
			break;
		}
	}
	queue->DeleteQueueRingBuffer();
	delete queue;
}