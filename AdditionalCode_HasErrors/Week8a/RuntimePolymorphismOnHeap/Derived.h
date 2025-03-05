#pragma once
#include "Base.h"

// When you call the constructor for derived
// Base constructor is automatically called
class Derived : public Base
{
public:
	Derived()
	{
		dynamicPtr = new int;
	}

	~Derived();

private:
	int* dynamicPtr;
};