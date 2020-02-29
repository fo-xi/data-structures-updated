#include "HashTable.h"
#include "InputOutput.h"
#include "NewHashTable.h"

using namespace std;

void HashTable::CreateHashTable()
{
	Capacity *= growthFactor;
	Length = 0;
	HashTable = new Node * [Capacity];
	for (int i = 0; i < Capacity; i++)
	{
		HashTable[i] = new Node();
	}
}

int HashTable::HashFunction(string key)
{
	long unsigned int hash = 0;
	for (int i = 0; i < key.length(); i++)
	{
		hash += (int)key[i] * pow(primeNumber, i);
	}
	hash %= Capacity;
	return hash;
}

bool HashTable::Insert(string key, string value)
{
	int index = HashFunction(key);
	if (HashTable[index]->Key.empty())
	{
		HashTable[index]->Key = key;
		HashTable[index]->Value = value;
	}
	else if (HashTable[index]->Key == key && HashTable[index]->Value == value)
	{
		return false;
	}
	else
	{
		if (!Chaining(key, value))
		{
			return false;
		}
	}
	Length++;
	if ((double)Length / (double)Capacity > fillFactor)
	{
		if (!Rehashing())
		{
			return false;
		}
	}
}

bool HashTable::Search(string key, string& value)
{
	int index = HashFunction(key);
	Node* temp = HashTable[index];
	while (temp != nullptr)
	{
		if (temp->Key == key)
		{
			value = temp->Value;
			return true;
		}
		temp = temp->Next;
	}
	return false;
}

bool HashTable::Chaining(string key, string value)
{
	int index = HashFunction(key);
	Node* temp = HashTable[index];
	Node* newElement = new Node;
	newElement->Key = key;
	newElement->Value = value;
	newElement->Next = nullptr;
	while (temp->Next != nullptr)
	{
		if (temp->Next->Key == newElement->Key &&
			temp->Next->Value == newElement->Value)
		{
			delete newElement;
			return false;
		}
		temp = temp->Next;
	}
	temp->Next = newElement;
	return true;
}

int HashTable::CountingElements(int index)
{
	Node* temp = HashTable[index];
	int number = 0;
	while (temp != nullptr)
	{
		number++;
		temp = temp->Next;
	}
	return number;
}

void HashTable::Remove(string key)
{
	int  index = HashFunction(key);
	Node* temp = HashTable[index];
	//Is there 1 element there?
	if (CountingElements(index) == 1 && HashTable[index]->Key == key)
	{
		HashTable[index]->Key = "";
		HashTable[index]->Value = "";
		HashTable[index]->Next = nullptr;
		return;
	}
	if (temp->Key == key)
	{
		HashTable[index] = temp->Next;
		delete temp;
		Remove(key);
		return;
	}
	Node* current = HashTable[index];
	while (temp != nullptr && !(HashTable[index]->Key.empty()))
	{
		if (temp->Key == key)
		{
			Node* deleteElement = temp;
			current->Next = deleteElement->Next;
			delete deleteElement;
			temp = current;
			Length--;
		}
		else
		{
			if (temp->Next != nullptr && temp->Next->Key != key)
			{
				current = current->Next;
			}
		}
		temp = temp->Next;
	}
}

void HashTable::DeleteHashTable()
{
	for (int i = 0; i < Capacity; i++)
	{
		while (HashTable[i] != nullptr)
		{
			Node* deleteItem = HashTable[i];
			HashTable[i] = HashTable[i]->Next;
			delete deleteItem;
		}
		delete HashTable[i];
	}
	Length = 0;
	delete HashTable;
}

bool HashTable::Rehashing()
{
	int temp = Length;
	int index = 0;
	NewHashTable* newHashTable = new NewHashTable[temp];
	for (int i = 0; i < Capacity; i++)
	{
		Node* current = HashTable[i];
		while (current != nullptr)
		{
			if (current->Key.empty())
			{
				current = current->Next;
				continue;
			}
			newHashTable[index].Key = current->Key;
			newHashTable[index].Value = current->Value;
			index++;
			current = current->Next;
		}
	}
	DeleteHashTable();
	CreateHashTable();
	for (int i = 0; i < temp; i++)
	{
		Insert(newHashTable[i].Key, newHashTable[i].Value);
	}
	delete[] newHashTable;
	return true;
}