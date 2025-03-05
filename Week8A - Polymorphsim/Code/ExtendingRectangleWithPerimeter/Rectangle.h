#pragma once

class Rectangle
{
public:
    Rectangle(double l, double w);

    double Area();

    double Perimeter();

private:
    double _length;
    double _width;
};