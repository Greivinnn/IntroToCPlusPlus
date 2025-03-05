#include <iostream>
#include <string>
#include "Weapon.h"

using namespace RPG;

Weapon::Weapon(std::string name, int damage, int level, std::string rarity)
	:_weaponName(name), _weaponDamage(damage), _weaponLevel(level), _weaponRarity(rarity)
{
}

