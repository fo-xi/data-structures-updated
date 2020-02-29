#include <iostream>
#include <string>
#include "InputOutput.h"
#include "HashTable.h"

using namespace std;

void ShowHashTable(HashTable* hashTable)
{
	system("cls");
	for (int i = 0; i < hashTable->Capacity; i++)
	{
		cout << endl;
		cout << "\nIndex ->" << i << '\t';
		Node* temp = hashTable->HashTable[i];
		while (temp != nullptr)
		{
			cout << endl;
			cout << "Key ->" << temp->Key << '\t';
			cout << "Value ->" << temp->Value << '\t';
			temp = temp->Next;
		}
	}
}

void ShowDictionary(Dictionary* dictionary)
{
	system("cls");
	for (int i = 0; i < dictionary->InnerHashTable->Capacity; i++)
	{
		Node* temp = dictionary->InnerHashTable->HashTable[i];
		if (temp->Key.empty())
		{
			continue;
		}
		cout << endl;
		cout << "\nIndex ->" << i << '\t';
		while (temp != nullptr)
		{
			cout << endl;
			cout << "Key ->" << temp->Key << '\t';
			cout << "Value ->" << temp->Value << '\t';
			temp = temp->Next;
		}
	}
}