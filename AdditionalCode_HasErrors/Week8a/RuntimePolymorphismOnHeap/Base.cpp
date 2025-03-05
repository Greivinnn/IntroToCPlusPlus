#include "Base.h"
#include <iostream>

Base::~Base()
{
	delete baseVariable;
	baseVariable = nullptr;
	std::cout << "Base destroyed!\n";
}
