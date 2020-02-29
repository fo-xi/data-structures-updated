#include <iostream>
#include "InputOutput.h"
#include "MenuQueueTwoStack.h"
#include "QueueTwoStack.h"
#include "Stack.h"

using namespace std;

void MenuQueueTwoStack()
{
	setlocale(LC_ALL, "Rus");

	TwoStack* queue = new TwoStack();
	Stack* mainStack = new Stack();
	Stack* secondaryStack = new Stack();

	bool isEnd = true;

	while (isEnd)
	{
		system("cls");
		ShowQueue(mainStack);
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
				int value = ReadNumber();
				queue->Enqueue(mainStack, value);
				break;
			}
			case 2:
			{
				queue->Dequeue(mainStack, secondaryStack);
				break;
			}
			case 3:
			{
				queue->DeleteQueue(mainStack);
				break;
			}
			case 4:
			{
				queue->ResizeStack(mainStack);
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
	queue->DeleteQueue(mainStack);
	delete mainStack;
	delete secondaryStack;
}