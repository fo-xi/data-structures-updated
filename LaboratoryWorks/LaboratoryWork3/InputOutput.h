#pragma once

#include "Stack.h"
#include "QueueTwoStack.h"
#include "RingBuffer.h"
#include "QueueRingBuffer.h"
#include "..\Common\ReadNumber.h"

void ShowStack(Stack* stack);
void ShowQueue(Stack* stack);
bool IsEmpty(int head, int tail);
void ShowRingBuffer(RingBuffer* ring);
void FreePlace(int capacity, int length);
void UsedPlace(int length);
void ShowQueueRingBuffer(QueueRingBuffer* queue);