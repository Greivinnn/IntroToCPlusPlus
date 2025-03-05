#include <iostream>
#include "Rectangle.h"

using namespace std;

int main()
{
    Rectangle rect(5, 3);
    cout << "Area: " << rect.Area() << endl;
    cout << "Perimeter: " << rect.Perimeter() << endl;

    return 0;
}