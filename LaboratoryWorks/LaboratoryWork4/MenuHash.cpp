#include <iostream>
#include "InputOutput.h"
#include "MenuHash.h"
#include "HashTable.h"

using namespace std;

void MenuHash()
{
	setlocale(LC_ALL, "Rus");

	HashTable* hashTable = new HashTable;

	bool isEnd = true;

	hashTable->CreateHashTable();

	while (isEnd)
	{
		ShowHashTable(hashTable);
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Add value to hash - table" << endl;
		cout << "2. Remove value from hash - table" << endl;
		cout << "3. Find the value in the hash - table" << endl;
		cout << "4. Add multiple values ​​to the hash - table" << endl;
		cout << "5. Exit" << endl;
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
				hashTable->Insert(key, value);
				break;
			}
			case 2:
			{
				cout << "Enter the key whose value you want to delete ->\t";
				string key;
				cin >> key;
				hashTable->Remove(key);
				break;
			}
			case 3:
			{
				cout << "Enter the key whose value you want to find ->\t";
				string key;
				cin >> key;
				string valueForSearch;
				if (hashTable->Search(key, valueForSearch))
				{
					cout << "Value ->\t" << valueForSearch << endl;
				}
				else
				{
					cout << "Value not found!" << endl;
				}
				system("pause");
				break;
			}
			case 4:
			{
				cout << "Amount of elements ->\t";
				int quantity = ReadNumber();
				cout << endl;
				for (int i = 0; i < quantity; i++)
				{
					hashTable->Insert(to_string(rand() % 100), to_string(rand() % 100));
				}
				break;
			}
			case 5:
			{
				isEnd = false;
				break;
			}
		default:
			break;
		}
	}
	hashTable->DeleteHashTable();
	delete hashTable;
}