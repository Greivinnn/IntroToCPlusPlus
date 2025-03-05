#include "Porsche.h"
#include <iostream>

int Porsche::Count;

Porsche::Porsche(int speed)
	:_speed(speed)
{
}

void Porsche::PrintSpeed()
{
	std::cout << "Speed is : " << _speed;
}