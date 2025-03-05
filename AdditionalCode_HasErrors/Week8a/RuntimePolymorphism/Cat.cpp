#include "Cat.h"
#include <iostream>

void Cat::MakeSound()
{
	// This forces to call the base implementation of the function
	Animal::MakeSound();
	std::cout << "Meow!\n";
}

void Cat::Scratch()
{
	std::cout << "Scratching!\n" << catVariable << "\n";
}