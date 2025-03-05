#include "Derived.h"
#include <iostream>

Derived::~Derived()
{
	delete dynamicPtr;
	dynamicPtr = nullptr;

	std::cout << "Derived destroyed!\n";
}
