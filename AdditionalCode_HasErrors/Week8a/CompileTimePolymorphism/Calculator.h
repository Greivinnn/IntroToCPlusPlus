#pragma once
#include <iostream>

class Calculator
{
public:
	// Constructor overloading
	Calculator(int value)
		:_value(value), _someOtherValue(0)
	{
	}

	Calculator(int value, int someOtherValue)
		:_value(value), _someOtherValue(someOtherValue)
	{
	}

	~Calculator()
	{
		std::cout << "I am being destroyed\n";
	}

	// Function overloading
	int Add(int a, int b);

	double Add(double a, double b);

private:
	int _value;
	int _someOtherValue;
};