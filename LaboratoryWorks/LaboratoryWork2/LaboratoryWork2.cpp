#include <iostream>
#include "ListItem.h"
#include "List.h"
#include "InputOutput.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	List* list = new List();

	while (true)
	{
		ShowList(list);
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Fill the list with random numbers" << endl;
		cout << "2. Remove element from list" << endl;
		cout << "3. Insert element to top of list" << endl;
		cout << "4. Insert element to end of list" << endl;
		cout << "5. Insert an element in front of a specific list element" << endl;
		cout << "6. Insert element after specific list element" << endl;
		cout << "7. Sorting" << endl;
		cout << "8. Line element search in list" << endl;
		cout << endl;
		cout << "SELECT AN ACTION :\t";

		switch (ReadNumber())
		{
		case 1:
		{
			cout << "Amount of elements ->\t";
			int quantity = ReadNumber();
			AddingRandomNumbers(list, quantity);
			ShowList(list);
			break;
		}
		case 2:
		{
			cout << "Index ->\t";
			int index = ReadNumber();
			RemoveFromList(list, index);
			ShowList(list);
			break;
		}
		case 3:
		{
			cout << "Value ->\t";
			int value = ReadNumber();
			InsertToList(list, 0, value);
			ShowList(list);
			break;
		}
		case 4:
		{
			cout << "Value ->\t";
			int value = ReadNumber();
			InsertToList(list, list->Size, value);
			ShowList(list);
			break;
		}
		case 5:
		{
			cout << "Index ->\t";
			int index = ReadNumber();
			cout << "Value ->\t";
			int value = ReadNumber();
			InsertToList(list, index, value);
			ShowList(list);
			break;
		}
		case 6:
		{
			cout << "Index ->\t";
			int index = ReadNumber();
			cout << "Value ->\t";
			int value = ReadNumber();
			InsertToList(list, index + 1, value);
			ShowList(list);
			break;
		}
		case 7:
		{
			SortingList(list);
			ShowList(list);
			break;
		}
		case 8:
		{
			cout << "Value ->\t";
			int value = ReadNumber();
			int index;
			if (!LineSearch(list, value, index))
			{
				cout << "Value not found!" << endl;
			}
			else
			{
				cout << "Index of found value ->\t" << index << endl;
			}
			system("pause");
			break;
		}
		default:
			break;
		}
	}
	return 0;
}