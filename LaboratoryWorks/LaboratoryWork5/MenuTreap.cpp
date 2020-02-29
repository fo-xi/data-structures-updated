#include <iostream>
#include "MenuTreap.h"
#include "InputOutput.h"

using namespace std;

void MenuTreap()
{
	setlocale(LC_ALL, "Rus");

	Treap* treap = new Treap;

	bool isEnd = true;
	int level = 0;

	while (isEnd)
	{
		system("cls");
		ShowTreap(treap->Root, level);
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Add element (unoptimized algorithm)" << endl;
		cout << "2. Delete element (unoptimized algorithm)" << endl;
		cout << "3. Add element (optimized algorithm)" << endl;
		cout << "4. Delete element (optimized algorithm)" << endl;
		cout << "5. Element search" << endl;
		cout << "6. Exit" << endl;
		cout << endl;
		cout << "SELECT AN ACTION :\t";

		switch (ReadNumber())
		{
			case 1:
			{
				cout << "Value ->\t";
				int value = ReadNumber();
				treap->Root = treap->AddUsingUnoptimizedAlgorithm(value);
				break;
			}
			case 2:
			{
				cout << "Value ->\t";
				int value = ReadNumber();
				treap->Root = treap->RemoveUsingUnoptimizedAlgorithm(value);
				break;
			}
			case 3:
			{
				cout << "Value ->\t";
				int value = ReadNumber();
				treap->Root = treap->AddUsingOtimizedAlgorithm(treap->Root, value);
				break;
			}
			case 4:
			{
				cout << "Value ->\t";
				int value = ReadNumber();
				treap->Root = treap->RemoveUsingOtimizedAlgorithm(treap->Root, value);
				break;
			}
			case 5:
			{
				cout << "Value ->\t";
				int value = ReadNumber();
				int priority;
				treap->SearchElement(value, priority);
				system("pause");
				break;
			}
			case 6:
			{
				isEnd = false;
				break;
			}
		default:
			break;
		}
	}
	if (treap->Root != nullptr)
	{
		treap->DeleteTreap(treap->Root);
	}
	delete treap;
}