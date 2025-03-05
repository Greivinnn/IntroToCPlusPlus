#include "Calculator.h"
#include <iostream>

void Test()
{
	// Compile time polymorphism
	Calculator calc(10);

	std::cout << "Integer Addition: " << calc.Add(3, 5) << "\n";
	std::cout << "Double Addition: " << calc.Add(3.5, 5.5) << "\n";
}

int main()
{
	//Test();
	Calculator calc(10);

	while(true)
	{
		//Some logic here
		{
			Calculator calc(50);
		}


















		
	}
	

	return 0;
}