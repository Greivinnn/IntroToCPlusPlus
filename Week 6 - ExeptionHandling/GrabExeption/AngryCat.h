#pragma once
#include <stdexcept>
#include <string>

namespace Week6a
{
	class AngryCatException : public std::runtime_error
	{
	public:
		AngryCatException();
		AngryCatException(std::string message);
	};
}


