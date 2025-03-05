#pragma once
#include <iostream>

class Animal
{
public:
	// No default constructor

	// Overloaded constructor
	Animal(int animalVar)
	{
		_animalVariable = animalVar;
	}

	Animal(bool state)
	{

	}
	virtual ~Animal()
	{
		std::cout << "Generic Animal is destroying\n";
	}

	virtual void MakeSound();

	void Eat();
	int _animalVariable;

private:
};