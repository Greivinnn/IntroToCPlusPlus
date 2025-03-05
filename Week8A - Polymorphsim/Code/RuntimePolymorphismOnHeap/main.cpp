#include "Base.h"
#include "Derived.h"


int main()
{
    Base* ptr = new Derived();
    delete ptr;  // Calls both Derived and Base destructors
    ptr = nullptr;
    return 0;
}