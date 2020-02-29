#include <iostream>
#include "List.h"
#include "InputOutput.h"

using namespace std;

void ShowList(List* list)
{
	system("cls");
	cout << "List: " << endl;

	Node* current = list->Head;

	while (current != nullptr)
	{
		cout << current->Data << "\t";
		current = current->Next;
	}
	cout << "\n\nQuantity ->\t" << list->Size << endl;
}