#pragma once
#include <iostream>
#include <string>

class Dog
{
public:
	Dog(std::string name, std::string breed);

	std::string GetName()
	{
		return _name;
	}
	std::string GetBreed()
	{
		return _breed;
	}
private:
	std::string _name;
	std::string _breed;
};