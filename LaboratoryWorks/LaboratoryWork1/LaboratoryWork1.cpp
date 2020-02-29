#include "InputOutput.h"
#include <iostream>
#include "Functions.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Array* array = new Array;

	FillArray(array);

	while (true)
	{
		ShowArray(array);
		cout << endl;
		cout << "MENU" << endl;
		cout << "1: Removing an element from an array" << endl;
		cout << "2: Insert element at the beginning of the array" << endl;
		cout << "3: Insert element at end of array" << endl;
		cout << "4: Insert an element after a specific array element" << endl;
		cout << "5: Sorting" << endl;
		cout << "6: Linear search for an element in an array" << endl;
		cout << "7: Binary search for an element in an array" << endl;

		switch (ReadNumber())
		{
			case 1:
			{
				cout << "Enter the position of the array whose element you want to delete ->\t";
				int index = ReadNumber();
				DeleteElement(array, index);
				break;
			}
			case 2:
			{
				cout << "Element ->\t" << endl;
				int number = ReadNumber();
				InsertByIndex(array, 0, number);
				break;
			}
			case 3:
			{
				cout << "Element ->\t" << endl;
				int number = ReadNumber();
				InsertByIndex(array, array->Length, number);
				break;
			}
			case 4:
			{
				cout << "Index ->\t" << endl;
				int index = ReadNumber();
				cout << "Element ->\t" << endl;
				int number = ReadNumber();
				InsertByIndex(array, index + 1, number);
				break;
			}
			case 5:
			{
				Sorting(array);
				break;
			}
			case 6:
			{
				cout << "Element ->\t" << endl;
				int number = ReadNumber();
				int index;
				if (!LineSearch(array, number, index))
				{
					cout << "Element not found!" << endl;
				}
				else
				{
					cout << "Index of element found ->\t" << index << endl;
				}
				system("pause");
				break;
			}
			case 7:
			{
				Sorting(array);
				ShowArray(array);
				cout << "Element ->\t" << endl;;
				int number = ReadNumber();
				int index;
				if (!BinarySearch(array, number, index))
				{
					cout << "Element not found!" << endl;
				}
				else
				{
					cout << "Index of element found ->\t" << index << endl;
				}
				system("pause");
				break;
			}
		default:
			break;
		}
	}
	delete[] array->Array;
	return 0;
}
