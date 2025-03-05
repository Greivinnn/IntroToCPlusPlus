#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

#include <vector>

int main()
{
	{


		// Compile time polymorphism
		Animal animal;
		animal.MakeSound();

		Cat cat;
		cat.MakeSound();

		Animal* animalPtr;
		Cat kitten;
		Dog dog;

		// Using base pointer to point to a derived class
		//animalPtr = &kitten; // Animal pointer points to the address of a Cat
		animalPtr = &dog;

		// This is going to call the Cat's version of MakeSound
		animalPtr->MakeSound();

		animalPtr->Eat();

		// Casting the Animal* to behave like a Cat*
		// we need to make sure animal pointer points to the address of a cat
		// static_cast<Cat*>()
		((Cat*)(animalPtr))->Scratch(); // C-style cast
	}

	std::vector<Animal*> animals;
	animals.push_back(new Cat());
	animals.push_back(new Dog());

	for (Animal* animal : animals)
	{
		// If you need to check whether your base pointer is pointing to
		// a derived object, do dynamic cast
		Cat* castedAnimal = dynamic_cast<Cat*>(animal);
		if (castedAnimal != nullptr)
		{
			castedAnimal->Scratch();
		}

		animal->MakeSound();
	}

	for (Animal* animal : animals)
	{
		delete animal;
		animal = nullptr;
	}
	

	return 0;
}