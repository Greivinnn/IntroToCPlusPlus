#include <iostream>
#include <array>
#include "Inventory.h"

using namespace Practice;

int main()
{
	// Array of inventory of 5 items
	Inventory items[5];

	// int array representing the things inside the inventory 
	// for loop that sets each number of the array in the items array
	int numbers[5] = { 10, 12, 24, 55, 40 };
	for (int i = 0; i < 5; i++)
	{
		items[i].SetItemNumber(numbers[i]);
	}

	Inventory* invPtr = items; // use a pointer to traverse the items array

	// Calculate the total numbers of items using the pointer
	int totalItems = 0;
	for (int i = 0; i < 5; i++)
	{
		totalItems += (invPtr + i)->GetItemNumber(); // access each index with the pointer 
	}

	std::cout << "Total number of items in inventory: " << totalItems << "\n";

	int bigNum = invPtr[0].GetItemNumber(); // start the pointer at the first array number
	int maxIndex = 0; // this will be the index of the biggest number

	for (int i = 1; i < 5; i++)
	{
		int currentNum = (invPtr + i)->GetItemNumber();
		if (currentNum > bigNum)
		{
			bigNum = currentNum; // if the number is bigger than prevoius number set the new one as the bigNum
			maxIndex = i;
		}
	}

	std::cout << "Item with the highest quantity: " << bigNum << "\n";
	std::cout << "Index of the item: " << maxIndex << '\n';

	return 0;
}
