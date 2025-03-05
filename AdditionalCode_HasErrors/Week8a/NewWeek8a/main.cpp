#include "Porsche.h"
#include <iostream>

int main()
{
	Porsche porsche1(100);

	Porsche::Count = 0;

	porsche1.Move();
	std::cout << "Count: " << Porsche::Count << "\n";
	Porsche::Count++;

	Porsche porsche2(200);
	porsche2.Move();
	std::cout << "Count: " << Porsche::Count << "\n";
	Porsche::Count++;

	Porsche porsche3(300);
	porsche3.Move();
	std::cout << "Count: " << Porsche::Count << "\n";
	Porsche::Count++;

	Porsche porsche4(400);
	porsche4.Move();
	std::cout << "Count: " << Porsche::Count << "\n";
	Porsche::Count++;

	return 0;
}