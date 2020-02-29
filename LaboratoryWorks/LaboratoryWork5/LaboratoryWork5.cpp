#include <iostream>
#include "InputOutput.h"
#include "MenuBinaryTree.h"
#include "MenuTreap.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	while (true)
	{
		system("cls");
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Binary tree" << endl;
		cout << "2. Treap" << endl;

		cout << endl;
		cout << "SELECT AN ACTION :\t";

		switch (ReadNumber())
		{
			case 1:
			{
				MenuBinaryTree();
				break;
			}
			case 2:
			{
				MenuTreap();
				break;
			}
		default:
			break;
		}
	}
	return 0;
}
