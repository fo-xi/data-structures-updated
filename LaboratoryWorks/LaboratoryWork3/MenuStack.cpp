#include <iostream>
#include "InputOutput.h"
#include "MenuStack.h"
#include "Stack.h"

using namespace std;

void MenuStack()
{
	setlocale(LC_ALL, "Rus");

	Stack* stack = new Stack();

	bool isEnd = true;

	while (isEnd)
	{
		system("cls");
		ShowStack(stack);
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Add value to stack" << endl;
		cout << "2. Pop value from stack" << endl;
		cout << "3. Delete stack" << endl;
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
				stack->Push(value);
				break;
			}
			case 2:
			{
				stack->Pop();
				break;
			}
			case 3:
			{
				stack->DeleteStack();
				break;
			}
			case 4:
			{
				stack->ResizeStack();
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
	stack->DeleteStack();
	delete stack;
}