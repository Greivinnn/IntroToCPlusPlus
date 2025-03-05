#include <iostream>
#include <stdexcept>
#include <string>
#include "InventoryException.h"

using namespace Practice;

InventoryException::InventoryException(std::string message)
	:std::out_of_range(message)
{
}
