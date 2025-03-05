#include <iostream>
#include <string>
#include <vector>
#include "Weapon.h"

using namespace Practice;

Weapon::Weapon(std::string name, float durability, int damage, std::string rarity)
	:M_weaponName(name), M_durability(durability), M_weaponDamage(damage), M_rarity(rarity)
{
}

std::string Weapon::GetName()
{
	return M_weaponName;
}

void Weapon::printWeaponDetails()
{
	std::cout << "Weapon Name: " << M_weaponName << "\nWeapon Durability: " << M_durability << "\nWeapon Damage : " << M_weaponDamage << "\nWeapon Rarity : " << M_rarity << "\n\n";
}

void Weapon::useWeapon()
{
	float temp = 0.1;
	temp *= M_durability;
	M_durability -= temp;
}
