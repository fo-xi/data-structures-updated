#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Node
{
	string Key;
	string Value;
	Node* Next;

	Node()
	{
		Key = "";
		Value = "";
		Next = nullptr;
	}
};