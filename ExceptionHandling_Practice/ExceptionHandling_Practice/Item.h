#pragma once
#include <string>

namespace Practice
{
	class Item
	{
	public:
		Item(std::string name);
		std::string GetName();
	private:
		std::string _itemName;
	};
}
