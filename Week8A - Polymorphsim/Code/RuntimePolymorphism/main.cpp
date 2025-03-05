#include "Cat.h"

int main()
{
    Animal* animal;
    Cat myCat;

    animal = &myCat;
    animal->MakeSound(); // Calls Cat's MakeSound due to runtime polymorphism

    return 0;
}