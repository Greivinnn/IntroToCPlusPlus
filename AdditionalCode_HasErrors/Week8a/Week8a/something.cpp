#include "something.h"
#include <iostream>

Porche::Porche(int hp)
	:_speed(hp)
{

}

void Porche::PrintSpeed()
{
	std::cout << "HP is : " << _speed;
}