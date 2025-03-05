#pragma once

#include "Car.h"

class Porsche : public Car
{
public:
	static int Count;

	Porsche(int speed);

	void PrintSpeed();

private:
	int _speed;
};