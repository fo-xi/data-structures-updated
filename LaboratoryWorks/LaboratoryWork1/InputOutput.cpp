#include "InputOutput.h"
#include <iostream>

using namespace std;

void ShowArray(Array* array)
{
	system("cls");
	cout << "Array: " << endl;
	for (int i = 0; i < array->Length; i++)
	{
		cout << array->Array[i] << '\t';
	}
	cout << endl;
}