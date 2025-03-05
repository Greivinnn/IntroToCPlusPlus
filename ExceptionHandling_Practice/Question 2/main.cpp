#include <iostream>
#include <string>
#include "Character.h"  
#include "CharacterExceptions.h"

using namespace Practice;

int main()
{
    Character char1("Santi", -1, 20);
    Character char2("Alfred", 190, 10);
    char1.Fight(char1, char2);

    return 0;
}
