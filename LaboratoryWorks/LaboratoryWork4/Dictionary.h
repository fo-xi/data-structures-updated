#pragma once

#include "HashTable.h"
#include <string>

using namespace std;

struct Dictionary
{
	HashTable* InnerHashTable = new HashTable;

	void CreateDictionary();
	void Insert(string, string);
	void Find(string, string&);
	void Remove(string);
	void DeleteDictionary();
};