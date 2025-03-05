#pragma once
#include <string>

namespace Week6a
{
    class Dog
    {
    public:
        Dog(std::string breed);

        std::string GetBreed();

    private:
        std::string _breed;
    };
}
