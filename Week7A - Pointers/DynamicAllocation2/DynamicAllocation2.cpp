#include <iostream>
#include "Dog.h"

int main()
{
    // Dog allocated on Heap
    Dog* myDogPtr = new Dog("Rover", "German Shepard");

    Dog* yourDogPtr = new Dog("Fide", "Beagle");

    myDogPtr->GetName();

    //After everything make sure to delete every pointer created
    // The C++ way allocates memory and calls the constructor when calling the names, Malloc cannot call a constructor thats why we do not use it in C++

    delete myDogPtr;
    myDogPtr = nullptr;
}
