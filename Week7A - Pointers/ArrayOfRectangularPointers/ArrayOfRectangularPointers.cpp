#include <iostream>
#include "Rectangle.h"
#include <string>
//Static Array Example
int main()
{
    Rectangle* rectArray[3];

    rectArray[0] = new Rectangle(4, 5);
    rectArray[1] = new Rectangle(6, 7);
    rectArray[2] = new Rectangle(8, 9);

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Rectangle " << i + 1 << ": Area = " << rectArray[i]->GetArea() << " Perimeter: " << rectArray[i]->GetPerimeter() << "\n\n";

        delete rectArray[i];
        rectArray[i] = nullptr;
    }
}

