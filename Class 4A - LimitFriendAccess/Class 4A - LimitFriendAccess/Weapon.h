#pragma once
#include <string>

class Weapon
{
public:
	Weapon(std::string name, int damage);

	friend void DisplayWeapon(Weapon weapon);

private:
	std::string _weaponName;
	int _weaponDamage;
};