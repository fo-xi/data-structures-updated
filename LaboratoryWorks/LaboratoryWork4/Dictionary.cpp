#include "Dictionary.h"

using namespace std;

void Dictionary::CreateDictionary()
{
	InnerHashTable->CreateHashTable();
}

void Dictionary::Insert(string key, string value)
{
	int index = InnerHashTable->HashFunction(key);
	Node* temp = InnerHashTable->HashTable[index];
	while (temp != nullptr)
	{
		if (temp->Key == key)
		{
			return;
		}
		temp = temp->Next;
	}
	InnerHashTable->Insert(key, value);
}

void Dictionary::Find(string key, string& value)
{
	if (InnerHashTable->Search(key, value))
	{
		cout << "Value ->\t" << value << endl;
	}
	else
	{
		cout << "Value not found!" << endl;
	}
}

void Dictionary::Remove(string key)
{
	InnerHashTable->Remove(key);
}

void Dictionary::DeleteDictionary()
{
	InnerHashTable->DeleteHashTable();
	delete InnerHashTable;
}