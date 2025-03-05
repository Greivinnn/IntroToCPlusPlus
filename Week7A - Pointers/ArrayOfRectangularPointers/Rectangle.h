#pragma once


class Rectangle
{
public:
	Rectangle(int l, int w)
	{
		_length = l;
		_width = w;
	}
	

	int GetArea()
	{
		return _length * _width;
	}
	int GetPerimeter()
	{
		return 2 * (_length + _width);
	}
private:
	int _length;
	int _width;
};