#include <iostream>
#include "InputOutput.h"
#include "MenuStack.h"
#include "MenuRingBuffer.h"
#include "MenuQueueTwoStack.h"
#include "MenuQueueRingBuffer.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	system("cls");

	while (true)
	{
		system("cls");
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Stack" << endl;
		cout << "2. Ring buffer" << endl;
		cout << "3. Queue based on two stacks" << endl;
		cout << "4. Queue using ring buffer" << endl;

		cout << endl;
		cout << "SELECT AN ACTION :\t";

		switch (ReadNumber())
		{
			case 1:
			{
				MenuStack();
				break;
			}
			case 2:
			{
				MenuRingBuffer();
				break;
			}
			case 3:
			{
				MenuQueueTwoStack();
				break;
			}
			case 4:
			{
				MenuQueueRingBuffer();
				break;
			}
		default:
			break;
		}
	}
	return 0;
}
