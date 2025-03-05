#include "Base.h"
#include "Derived.h"

int main()
{
	// Base ptr is allocating memory for the derived class
	// on the heap
	Base* ptr = new Derived();

	// Destructor is called
	delete (Derived*)ptr;
	ptr = nullptr;
}