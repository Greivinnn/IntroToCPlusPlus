#include <iostream>
#include <vector>
#include <string>
#include "Item.h"

using namespace Practice;

Item::Item(std::string name)
	:_itemName(name)
{
}

std::string Item::GetName()
{
	return _itemName;
}