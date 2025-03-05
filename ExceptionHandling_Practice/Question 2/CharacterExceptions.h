#pragma once
#include <stdexcept>
#include <iostream>
#include <string>

namespace Practice
{
	class CharacterExceptions : public std::runtime_error
	{
	public:
		CharacterExceptions(std::string message);
	};
}