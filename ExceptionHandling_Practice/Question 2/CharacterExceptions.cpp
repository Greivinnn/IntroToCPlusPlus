#include <iostream>
#include <stdexcept>
#include <string>
#include "CharacterExceptions.h"

using namespace Practice;

CharacterExceptions::CharacterExceptions(std::string message)
	:runtime_error(message)
{
}