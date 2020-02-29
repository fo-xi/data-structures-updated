#include <iostream>
#include "InputOutput.h"
#include "MenuHash.h"
#include "MenuDictionary.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	while (true)
	{
		system("cls");
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Dictionary" << endl;
		cout << "2. Hash - table" << endl;

		cout << endl;
		cout << "SELECT AN ACTION :\t";

		switch (ReadNumber())
		{
			case 1:
			{
				MenuDictionary();
				break;
			}
			case 2:
			{
				MenuHash();
				break;
			}
		default:
			break;
		}
	}
	return 0;
}
