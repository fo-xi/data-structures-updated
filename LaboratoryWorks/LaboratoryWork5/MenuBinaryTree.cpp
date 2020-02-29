#include <iostream>
#include "MenuBinaryTree.h"
#include "InputOutput.h"

using namespace std;

void MenuBinaryTree()
{
	setlocale(LC_ALL, "Rus");

	BinaryTree* binaryTree = new BinaryTree;

	bool isEnd = true;
	int level = 0;

	while (isEnd)
	{
		system("cls");
		ShowBinaryTree(binaryTree->Root, level);
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Add element" << endl;
		cout << "2. Delete element" << endl;
		cout << "3. Minimum element search" << endl;
		cout << "4. Maximum element search" << endl;
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
				binaryTree->Root = binaryTree->AddElement(binaryTree->Root, value);
				break;
			}
			case 2:
			{
				cout << "Value ->\t";
				int value = ReadNumber();
				binaryTree->Root = binaryTree->RemoveElement(binaryTree->Root, value);
				break;
			}
			case 3:
			{
				if (binaryTree->Root == nullptr)
				{
					cout << "No element";
				}
				else
				{
					cout << binaryTree->SearchMin(binaryTree->Root)->Data << endl;
				}
				system("pause");
				break;
			}
			case 4:
			{
				if (binaryTree->Root == nullptr)
				{
					cout << "No element";
				}
				else
				{
					cout << binaryTree->SearchMax(binaryTree->Root)->Data << endl;
				}
				system("pause");
				break;
			}
			case 5:
			{
				cout << "Value ->\t";
				int value = ReadNumber();
				ShowElement(binaryTree, value);
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
	if (binaryTree->Root != nullptr)
	{
		binaryTree->DeleteBinaryTree(binaryTree->Root);
	}
	delete binaryTree;
}