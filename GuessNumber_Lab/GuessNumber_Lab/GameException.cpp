#include "GameException.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace Lab;

GameException::GameException(std::string message)
	:std::out_of_range(message)
{
}