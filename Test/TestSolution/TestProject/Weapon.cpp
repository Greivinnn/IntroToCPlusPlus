#include "Weapon.h"

#include <iostream>

using namespace Practice;

Weapon::Weapon(std::string name, int damage, std::string rarity)
	: _name(name), _damage(damage), _rarity(rarity)
{
}

void Weapon::PrintWeaponDetails()
{
	std::cout << "Name: " << _name << "\n";
	std::cout << "Damage: " << _damage << "\n";
	std::cout << "Rarity: " << _rarity << "\n";
}

void Weapon::IncreaseDamageByPercent(int damagePercent)
{
	_damage += _damage * ((float)damagePercent / 100.0f);
}

std::string Weapon::GetName()
{
	return _name;
}