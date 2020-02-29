#include <iostream>
#include "InputOutput.h"
#include "MenuAVLTree.h"
#include "MenuRBTree.h"

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
		cout << "1. AVL - tree" << endl;
		cout << "2. Red - black tree" << endl;

		cout << endl;
		cout << "SELECT AN ACTION :\t";

		switch (ReadNumber())
		{
			case 1:
			{
				MenuAVLTree();
				break;
			}
			case 2:
			{
				MenuRBTree();
				break;
			}
		default:
			break;
		}
	}
	return 0;
}
