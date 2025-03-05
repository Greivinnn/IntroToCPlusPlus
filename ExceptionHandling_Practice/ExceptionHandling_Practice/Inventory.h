#pragma once
#include <vector>
#include <string>
#include "Item.h"

namespace Practice
{
	class Inventory
	{
	public:
		Inventory();
		void AddItem(Item name);
		void RemoveItem(std::string name);
		void DisplayInventory();
	private:
		std::vector<Item> _inventoryList;
	};
}