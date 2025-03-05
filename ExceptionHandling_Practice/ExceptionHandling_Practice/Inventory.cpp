#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Inventory.h"
#include "InventoryException.h"

using namespace Practice;

Inventory::Inventory()
{
	_inventoryList.reserve(10);
}

void Inventory::AddItem(Item newItem)
{
	try
	{
		if (_inventoryList.capacity() != _inventoryList.size())
		{
			_inventoryList.push_back(newItem);
		}
		else
		{
			throw InventoryException("Inventory is full. Maximum of 10 items at once, all extra items were thrown away.");
		}
	}
	catch (InventoryException ex)
	{
		std::cout << "Caught an exception: " << ex.what() << "\n";
	}
}

void Inventory::RemoveItem(std::string name)
{
	try
	{
		for (int i = 0; i < _inventoryList.size(); i++)
		{
			if (_inventoryList[i].GetName().compare(name) == 0)
			{
				_inventoryList.erase(_inventoryList.begin() + i);
				std::cout << "Successfully deleted index number: " << i << "\n";
				return;
			}
			else
			{
				throw InventoryException("Invalid item. That item does not exist in your inventory");
				return;
			}
		}
	}
	catch (InventoryException ex)
	{
		std::cout << "Caught an exception: " << ex.what() << "\n";
	}
}

void Inventory::DisplayInventory()
{
	for (Item items : _inventoryList)
	{
		std::cout << items.GetName() << "\n";
	}
	std::cout << "\n";
}

