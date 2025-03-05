#include "Rectangle.h"

Rectangle::Rectangle(double l, double w) :
    _length(l), _width(w)
{
}

double Rectangle::Area()
{
    return _length * _width;
}

double Rectangle::Perimeter()
{
    return 2 * (_length + _width);
}