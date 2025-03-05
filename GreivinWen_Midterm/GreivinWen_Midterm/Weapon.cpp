#include <iostream>
#include <string>
#include "Weapon.h"

using namespace Midterm;

Weapon::Weapon(std::string name, int damage, std::string rarity)
	:_weaponName(name), _weaponDamage(damage), _weaponRarity(rarity)
{
}

std::string Weapon::GetWeaponName()
{
	return _weaponName;
}

int Weapon::GetWeaponDamage()
{
	return _weaponDamage;
}

std::string Weapon::GetWeaponRarity()
{
	return _weaponRarity;
}
