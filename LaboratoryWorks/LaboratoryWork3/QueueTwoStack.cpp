#include <iostream>
#include "InputOutput.h"
#include "QueueTwoStack.h"

void TwoStack::CreateStack(Stack* stack)
{
	stack->Capacity = queueSize;
	stack->Buffer = new int[stack->Capacity];
	stack->Top = -1;
	stack->Length = 0;
}

void TwoStack::ResizeStack(Stack* stack)
{
	if (stack->Top != -1)
	{
		stack->Capacity += queueSize;
		int* newArray = new int[stack->Capacity];
		for (int i = 0; i < stack->Length; i++)
		{
			newArray[i] = stack->Buffer[i];
		}
		delete[] stack->Buffer;
		stack->Buffer = newArray;
	}
	else
	{
		return;
	}
}

void TwoStack::PushMainStack(Stack* mainStack, int value)
{
	if (mainStack->Top == -1 && mainStack->Capacity == 0)
	{
		CreateStack(mainStack);
	}
	if (mainStack->Length < mainStack->Capacity)
	{
		mainStack->Top++;
		mainStack->Buffer[mainStack->Top] = value;
		mainStack->Length++;
	}
	else
	{
		return;
	}
}

void TwoStack::PushSecondaryStack(Stack* secondaryStack, int value)
{
	if (secondaryStack->Top == -1)
	{
		CreateStack(secondaryStack);
	}
	if ((secondaryStack->Length + 1) > secondaryStack->Capacity)
	{
		ResizeStack(secondaryStack);
		PushSecondaryStack(secondaryStack, value);
	}
	else
	{
		if (secondaryStack->Length < secondaryStack->Capacity)
		{
			secondaryStack->Top++;
			secondaryStack->Buffer[secondaryStack->Top] = value;
			secondaryStack->Length++;
		}
		else
		{
			return;
		}
	}
}

int TwoStack::PopStack(Stack* stack)
{
	int temp = stack->Buffer[stack->Top--];
	stack->Length--;
	return temp;
}

void TwoStack::Enqueue(Stack* mainStack, int value)
{
	PushMainStack(mainStack, value);
}

void TwoStack::Dequeue(Stack* mainStack, Stack* secondaryStack)
{
	int count = mainStack->Length;

	if ((mainStack->Top == -1) && (secondaryStack->Top == -1))
	{
		return;
	}
	else
	{
		for (int i = 0; i < count; i++)
		{
			int a = PopStack(mainStack);
			PushSecondaryStack(secondaryStack, a);
		}
		int b = PopStack(secondaryStack);
		count--;

		for (int i = 0; i < count; i++)
		{
			int a = PopStack(secondaryStack);
			PushMainStack(mainStack, a);
		}
		secondaryStack->Capacity = 0;
	}
}

void TwoStack::DeleteQueue(Stack* stack)
{
	if (!(stack->Top == -1))
	{
		delete[] stack->Buffer;
		stack->Top = -1;
		stack->Capacity = 0;
		stack->Length = 0;
	}
}