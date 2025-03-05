#pragma once
#include <stdexcept>
#include <iostream>
#include <string>

namespace Lab
{
	class GameException : public std::out_of_range
	{
	public:
		GameException(std::string message);
	};
}