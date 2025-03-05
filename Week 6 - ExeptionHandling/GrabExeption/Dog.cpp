#include "Dog.h"
#include <stdexcept>

using namespace Week6a;

Dog::Dog(std::string breed)
{
    if (breed.compare("Poodle") == 0)
    {
        throw std::runtime_error("Poodle? That's not a real dog");
    }

    _breed = breed;
}

std::string Dog::GetBreed()
{
    return _breed;
}