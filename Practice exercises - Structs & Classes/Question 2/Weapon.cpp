#include <iostream>
#include <string>
#include <vector>
#include "Weapon.h"

using namespace WeaponInfo;

Weapon::Weapon(std::string name, int damage, std::string rarity)
	:M_weaponName(name), M_weaponDamage(damage), M_rarity(rarity)
{
}

void Weapon::printWeaponDetails()
{
	std::cout << "Weapon Name: " << M_weaponName << "\nWeapon Damage: " << M_weaponDamage << "\nWeapon Rarity: " << M_rarity << "\n\n";
}

void Weapon::IncreaseDamage()
{
	M_weaponDamage *= 1.10;
}