#include <iostream>
#include "InputOutput.h"
#include "MenuDictionary.h"
#include "Dictionary.h"

using namespace std;

void MenuDictionary()
{
	setlocale(LC_ALL, "Rus");

	Dictionary* dictionary = new Dictionary;

	bool isEnd = true;

	dictionary->CreateDictionary();

	while (isEnd)
	{
		ShowDictionary(dictionary);
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Add value to dictionary" << endl;
		cout << "2. Remove value from dictionary" << endl;
		cout << "3. Find the value in the dictionary" << endl;
		cout << "4. Exit" << endl;
		cout << endl;
		cout << "SELECT AN ACTION :\t";

		switch (ReadNumber())
		{
			case 1:
			{
				cout << "Key ->\t";
				string key;
				cin >> key;
				cout << endl;

				cout << "Value ->\t";
				string value;
				cin >> value;
				cout << endl;
				dictionary->Insert(key, value);
				break;
			}
			case 2:
			{
				cout << "Enter the key whose value you want to delete ->\t";
				string key;
				cin >> key;
				dictionary->Remove(key);
				break;
			}
			case 3:
			{
				cout << "Enter the key whose value you want to find ->\t";
				string key;
				cin >> key;
				string valueForFind;
				dictionary->Find(key, valueForFind);
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
	dictionary->DeleteDictionary();
	delete dictionary;
}