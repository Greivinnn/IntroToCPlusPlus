#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "Weapon.h"

using namespace Practice;

Character::Character(std::string name, int health, int level)
	: M_name(name), M_health(health), M_level(level)
{
}

void Character::PrintStats()
{
	std::cout << "Name: " << M_name << "\nHealth: " << M_health << "hp\nPlayer Level: " << M_level << "\n\n";
}
