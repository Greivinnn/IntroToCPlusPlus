#pragma once
#include <iostream>

class ConstExample
{
public:
	ConstExample()
		:_constantVar(10)
	{
	}
	void ShowValue()
	{
		std::cout << "constantVar: " << _constantVar << "\n";
	}
	int GetVar()
	{
		return _constantVar;
	}
private:
	const int _constantVar;
};