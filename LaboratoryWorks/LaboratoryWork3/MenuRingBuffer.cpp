#include <iostream>
#include "InputOutput.h"
#include "MenuRingBuffer.h"
#include "RingBuffer.h"

using namespace std;

void MenuRingBuffer()
{
	setlocale(LC_ALL, "Rus");

	RingBuffer* ring = new RingBuffer();

	bool isEnd = true;

	int result = 0;

	ring->CreateRingBuffer();

	while (isEnd)
	{
		system("cls");
		ShowRingBuffer(ring);
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Add value to buffer" << endl;
		cout << "2. Extract value from buffer" << endl;
		cout << "3. Buffer free space" << endl;
		cout << "4. Buffer space occupied" << endl;
		cout << "5. Resize" << endl;
		cout << "6. Exit" << endl;

		cout << endl;
		cout << "SELECT AN ACTION :\t";

		switch (ReadNumber())
		{
			case 1:
			{
				cout << "Value ->\t";
				int value = ReadNumber();
				ring->AddElement(value, result);
				break;
			}
			case 2:
			{
				ring->GetElement(result);
				break;
			}
			case 3:
			{
				FreePlace(ring->Capacity, ring->Length);
				system("pause");
				break;
			}
			case 4:
			{
				UsedPlace(ring->Length);
				system("pause");
				break;
			}
			case 5:
			{
				ring->ResizeRingBuffer();
				break;
			}
			case 6:
			{
				isEnd = false;
				break;
			}
		default:
			break;
		}
	}
	ring->DeleteRingBuffer();
	delete ring;
}