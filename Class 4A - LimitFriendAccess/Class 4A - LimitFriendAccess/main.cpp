#include "Weapon.h"
#include <iostream>

void DisplayWeapon(Weapon weapon)
{
	std::cout << "Weapon: " << weapon._weaponName << "\nDamage: " << weapon._weaponDamage;
}

int main()
{
	Weapon weapon("sword", 10);
	DisplayWeapon(weapon);
}