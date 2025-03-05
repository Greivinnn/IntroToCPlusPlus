#pragma once
#include <stdexcept>
#include <iostream>
#include <string>

namespace Practice
{
	class InventoryException : public std::out_of_range
	{
	public:
		InventoryException(std::string message);
	};
}
