#include <iostream>
#include "Circle.h"

int main()
{
	int size;
	std::cout << "Enter number of circles: "; 
	std::cin >> size;

	// Circle* denotes a dynamic array here
	//Array of pointers
	Circle** circleArray = new Circle * [size];

	for (int i = 0; i < size; i++)
	{
		double radius;
		std::cout << "Enter circle radius for circle #" << i + 1 << "\n";
		std::cin >> radius;
	
		circleArray[i] = new Circle(radius);
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << "Circle #" << i + 1 << ":\nArea: " << circleArray[i]->GetArea() << "\nCircumference: " << circleArray[i]->GetCircumference() << "\n\n";

		delete circleArray[i];
		circleArray[i] = nullptr;
	}

	delete[] circleArray;
	circleArray = nullptr;
	
	return 0;
}
