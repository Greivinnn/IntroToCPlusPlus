#include "Character.h"
#include <iostream>
#include <string>
#include <vector>

using namespace CharacterInfo;

int main()
{
    Character Player1("Alfred", 100, 20);
    Character Villain("Ogre", 200, 50);
    
    std::cout << "Initial Stats:\n\n";
    Player1.PrintStats();
    Villain.PrintStats();

    std::cout << "Enemy attacks Player!" << std::endl;
    Player1.TakeDamage(Villain.GetDamage());

    std::cout << "\n\nThe Ogre hit you! This are the new stats:\n\n";
    Player1.PrintStats();
    Villain.PrintStats();

}
