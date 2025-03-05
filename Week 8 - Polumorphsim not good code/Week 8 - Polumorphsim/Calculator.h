#pragma once
#include <iostream>

class Calculator
{
public:
	int Add(int a, int b);
	double Add(double a, double b);
	~Calculator()
	{
		std::cout << "Hello";
	}
};