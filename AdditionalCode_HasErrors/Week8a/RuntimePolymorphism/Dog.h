#pragma once
#include "Animal.h"
#include <iostream>

class Dog : public Animal
{
public:

	~Dog()
	{
		std::cout << "Dog is destroying\n";
	}

	void MakeSound() override;
};