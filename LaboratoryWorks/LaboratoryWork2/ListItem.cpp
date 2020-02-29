#include <iostream>
#include "List.h"
#include "ListItem.h"

using namespace std;

void InsertToList(List* list, int index, int value)
{
	if (list->Head == nullptr || (index >= 0 && index <= list->Size))
	{
		Node* temp = new Node;
		temp->Data = value;
		if (list->Head == nullptr)
		{
			list->Head = temp;
			list->Size = 0;
			list->Head->Next = nullptr;
			list->Head->Prev = nullptr;
			list->Tail = list->Head;
		}
		//Insert the item at the top of the list
		else if (index == 0)
		{
			Node* temp = list->Head->Prev;
			temp = new Node;
			temp->Data = value;
			temp->Next = list->Head;
			list->Head->Prev = temp;
			list->Head = temp;
			list->Head->Prev = nullptr;
		}
		//Insert an item at the end of the list
		else if (index == list->Size)
		{
			list->Tail->Next = temp;
			temp->Prev = list->Tail;
			list->Tail = temp;
			list->Tail->Next = nullptr;
		}
		//Insert the item in the middle of the list
		else
		{
			Node* current = list->Head;
			for (int i = 0; i < index; i++)
			{
				current = current->Next;
			}
			current->Prev->Next = temp;
			temp->Prev = current->Prev;
			current->Prev = temp;
			temp->Next = current;
		}
		list->Size++;
	}
	else
	{
		return;
	}
}

void AddingRandomNumbers(List* list, int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		InsertToList(list, list->Size, 1 + rand() % 100);
	}
}

void RemoveFromList(List* list, int index)
{
	if (index >= 0 && index <= list->Size - 1)
	{
		//If the item to be deleted is the first one and there are still elements in this list
		if ((index == 0) && (list->Head->Next))
		{
			Node* temp = list->Head;
			list->Head = list->Head->Next;
			list->Head->Prev = nullptr;
			delete temp;
			list->Size--;
			return;
		}
		//If the item to be deleted is the first and there are no items in this list
		if ((index == 0) && (list->Head == list->Tail))
		{
			list->Head->Next = nullptr;
			list->Head = nullptr;
			delete list->Head;
			list->Size = 0;
			return;
		}

		//If the item to be deleted is the last item in the list
		if (index == list->Size - 1)
		{
			Node* temp = list->Tail;
			list->Tail = list->Tail->Prev;
			list->Tail->Next = nullptr;
			delete temp;
			list->Size--;
			return;
		}
		//The item to be deleted is somewhere in the middle of the list
		Node* temp = list->Head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->Next;
		}
		temp->Prev->Next = temp->Next;
		temp->Next->Prev = temp->Prev;
		delete temp;
		list->Size--;
	}
	else
	{
		return;
	}
}

void SortingList(List* list)
{
	for (int j = 0; j < list->Size; j++)
	{
		Node* left;
		Node* right;
		left = list->Head;
		right = list->Head->Next;
		for (int i = 1; i < list->Size - j; i++)
		{
			if (left->Data > right->Data)
			{
				left = right;
			}
			right = right->Next;
		}
		list->Tail->Next = left;
		if (left == list->Head)
		{
			list->Head->Next->Prev = nullptr;
			list->Head = list->Head->Next;
			list->Tail->Next = left;
			left->Next = nullptr;
			left->Prev = list->Tail;
			list->Tail = left;
		}
		else if ((left != list->Head) && (left != list->Tail))
		{
			left->Prev->Next = left->Next;
			left->Next->Prev = left->Prev;
			left->Prev = list->Tail;
			left->Next = nullptr;
			list->Tail->Next = left;
			list->Tail = left;
		}
	}
}

bool LineSearch(List* lst, int value, int& index)
{
	Node* temp = lst->Head;
	for (int i = 0; temp != nullptr; i++)
	{
		if (temp->Data == value)
		{
			index = i;
			return true;
		}
		temp = temp->Next;
	}
	return false;
}