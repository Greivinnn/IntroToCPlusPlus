#include "Animal.h"
#include <iostream>
#include "Dog.h"

using namespace Inheritance;

int main()
{
	Animal genericAnimal;

	genericAnimal.Shout();

	Dog dog;

	dog.Shout();

	dog.Bark();
	return 0;
}