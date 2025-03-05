#pragma once
#include "Animal.h"
#include <iostream>

class Cat : public Animal
{
public:
	// This will automatically call the
	// base Animal class constructor
	Cat(int variable)
		: Animal(true) // Explicitly call the base constructor
	{
		catVariable = 10;
		_animalVariable = 10;
	}

	~Cat()
	{
		std::cout << "Cat is destroying\n";
	}

	void MakeSound() override;

	void Scratch();

private:
	int catVariable;
};