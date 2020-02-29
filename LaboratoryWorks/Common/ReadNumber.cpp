#include "ReadNumber.h"
#include <iostream>

using namespace std;

int ReadNumber()
{
	bool error;
	int number;
	do
	{
		error = false;
		cin >> number;
		if (cin.fail())
		{
			cout << "Error\n";
			error = true;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error);
	return number;
}