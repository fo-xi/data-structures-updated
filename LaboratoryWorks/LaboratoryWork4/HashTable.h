#pragma once

#include "Node.h"

const double growthFactor = 1.5;
const int primeNumber = 21;
const double fillFactor = 0.7;

using namespace std;

struct HashTable
{
	Node** HashTable;
	int Capacity = 4;
	int Length;

	void CreateHashTable();
	int HashFunction(string);
	bool Insert(string, string);
	bool Search(string, string&);
	bool Chaining(string, string);
	void Remove(string);
	int CountingElements(int);
	void DeleteHashTable();
	bool Rehashing();
};