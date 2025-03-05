#include "AngryCat.h"
#include <stdexcept>
#include <string>

using namespace Week6a;

AngryCatException::AngryCatException()
	:std::runtime_error("The cat is angry")
{
}

AngryCatException::AngryCatException(std::string message)
	:std::runtime_error(message)
{
}