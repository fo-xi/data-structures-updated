#include <iostream>
#include"Functions.h"
#include <ctime>

using namespace std;

void FillArray(Array* array)
{
	array->Array = new int[array->Capacity];
	for (int i = 0; i < array->Length; i++)
	{
		array->Array[i] = 1 + rand() % 100;
	}
}

void Resize(Array* array)
{
	array->Capacity = array->Capacity + (array->Capacity / 2) + 1;
	int* newArray = new int[array->Capacity];
	for (int i = 0; i < array->Length; i++)
	{
		newArray[i] = array->Array[i];
	}
	delete[] array->Array;
	array->Array = newArray;
}

void DeleteElement(Array* array, int deleteIndex)
{
	if (array->Length != 0 && deleteIndex >= 0 && deleteIndex < array->Length)
	{
		for (int i = deleteIndex; i < array->Length; i++)
		{
			array->Array[i] = array->Array[i + 1];
		}
		array->Length = array->Length - 1;
	}
	else
	{
		return;
	}
}

void InsertByIndex(Array* array, int insertIndex, int value)
{
	int temp = 0;
	//If there is no space in the array
	if ((array->Length + 1 > array->Capacity))
	{
		Resize(array);
		InsertByIndex(array, insertIndex, value);
	}
	else
	{
		if (array->Length != 0 && insertIndex >= 0 && insertIndex <= array->Length)
		{

			if (insertIndex == 0)
			{
				array->Length++;

				for (int i = insertIndex; i < array->Length; i++)
				{
					temp = array->Array[i];
					array->Array[i] = value;
					value = temp;
				}
				return;
			}

			if (insertIndex == array->Length)
			{
				array->Length++;
				array->Array[array->Length - 1] = value;
				return;
			}

			if (insertIndex > 0)
			{
				array->Length++;
				for (int i = insertIndex; i < array->Length; i++)
				{
					temp = array->Array[i];
					array->Array[i] = value;
					value = temp;
				}
				return;
			}

		}
		else if (array->Length == 0)
		{
			array->Length++;
			for (int i = 0; i < array->Length; i++)
			{
				array->Array[i] = value;
			}
			return;
		}
		else
		{
			return;
		}
	}
}

void Sorting(Array* array)
{
	for (int i = 0; i < array->Length - 1; i++)
	{
		for (int j = 0; j < array->Length - i - 1; j++)
		{
			if (array->Array[j] > array->Array[j + 1])
			{
				int temp;
				temp = array->Array[j];
				array->Array[j] = array->Array[j + 1];
				array->Array[j + 1] = temp;
			}

		}
	}
}

bool LineSearch(Array* array, int value, int& index)
{
	for (int i = 0; i < array->Length; i++)
	{
		if (array->Array[i] == value)
		{
			index = i;
			return true;
		}
	}
	return false;
}

bool BinarySearch(Array* array, int value, int& index)
{
	int left = 0;
	int right = array->Length;

	while (left <= right)
	{
		int middle;
		middle = (left + right) / 2;

		if (value < array->Array[middle])
		{
			right = middle - 1;
		}
		else
		{
			if (value > array->Array[middle])
			{
				left = middle + 1;
			}
			else
			{
				index = middle;
				return true;
			}
		}
		if (left > right)
		{
			return false;
		}
	}
}