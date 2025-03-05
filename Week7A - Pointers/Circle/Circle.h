#pragma once

class Circle
{
public:
	Circle(double r)
	{
		_radius = r;
	}
	double GetArea()
	{
		return 3.14 * _radius * _radius;
	}
	
	double GetCircumference()
	{
		return 2 * 3.14 * _radius;
	}
private:
	double _radius;
};