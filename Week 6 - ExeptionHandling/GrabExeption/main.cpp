#include <iostream>
#include <stdexcept>
#include "Dog.h"
#include "AngryCat.h"

using namespace Week6a;

/*
char GetLetterGrade(int percent)
{
    if (percent < 0 || percent > 100)
    {
        throw std::out_of_range("Your percent is out of range 0 to 100");
    }

    if (percent >= 90)
    {
        return 'A';
    }
    else if (percent >= 80)
    {
        return 'B';
    }
    else
    {
        return 'F';
    }
}
*/

void FedKitty(int treat)
{
    if (treat < 5)
    {
        throw AngryCatException("Kitty is not satisfied");
    }

    std::cout << "Thank you kitty is happy\n";
}

int main()
{
    try
    {
        FedKitty(8);
    }
    catch (AngryCatException ex)
    {
        std::cout << "Caught an exception: " << ex.what() << "\n";
    }

    return 0;
}
