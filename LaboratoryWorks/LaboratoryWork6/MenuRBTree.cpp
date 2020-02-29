#include <iostream>
#include "MenuRBTree.h"
#include "InputOutput.h"

using namespace std;

void MenuRBTree()
{
	setlocale(LC_ALL, "Rus");

	RBTree* rbTree = new RBTree;

	bool isEnd = true;
	int level = 0;

	//Missing pointers are marked with pointers to a dummy node - Nil
	rbTree->Nil = new RBTreeNode();
	rbTree->Nil->Color = BLACK;

	while (isEnd)
	{
		system("cls");
		ShowRBTree(rbTree->Root, level, rbTree->Nil);
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Add element" << endl;
		cout << "2. Delete element" << endl;
		cout << "3. Element search" << endl;
		cout << "4. Exit" << endl;
		cout << endl;
		cout << "SELECT AN ACTION :\t";

		switch (ReadNumber())
		{
			case 1:
			{
				cout << "Value ->\t";
				int value = ReadNumber();
				rbTree->InsertElement(value);
				break;
			}
			case 2:
			{
				cout << "Value ->\t";
				int value = ReadNumber();
				rbTree->RemoveElement(value);
				break;
			}
			case 3:
			{
				cout << "Value ->\t";
				int value = ReadNumber();
				ShowElementRBTree(rbTree, value);
				system("pause");
				break;
			}
			case 4:
			{
				isEnd = false;
				break;
			}
		default:
			break;
		}
	}
	if (rbTree->Root != nullptr)
	{
		rbTree->DeleteRBTree(rbTree->Root);
	}
	delete rbTree;
}