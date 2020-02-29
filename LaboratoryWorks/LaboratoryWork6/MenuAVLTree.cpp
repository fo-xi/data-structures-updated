#include <iostream>
#include "MenuAVLTree.h"
#include "InputOutput.h"

using namespace std;

void MenuAVLTree()
{
	setlocale(LC_ALL, "Rus");

	AVLTree* avlTree = new AVLTree;

	bool isEnd = true;
	int level = 0;

	while (isEnd)
	{
		system("cls");
		ShowAVLTree(avlTree->Root, level);
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
				avlTree->Root = avlTree->AddElement(avlTree->Root, value);
				break;
			}
			case 2:
			{
				cout << "Value ->\t";
				int value = ReadNumber();
				avlTree->Root = avlTree->RemoveElement(avlTree->Root, value);
				break;
			}
			case 3:
			{
				cout << "Value ->\t";
				int value = ReadNumber();
				ShowElementAVLTree(avlTree, value);
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
	if (avlTree->Root != nullptr)
	{
		avlTree->DeleteAVLTree(avlTree->Root);
	}
	delete avlTree;
}