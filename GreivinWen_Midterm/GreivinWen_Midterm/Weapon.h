#pragma once
#include <string>

namespace Midterm
{
	class Weapon
	{
	public:
		Weapon(std::string name, int damage, std::string rarity);
		std::string GetWeaponName();
		int GetWeaponDamage();
		std::string GetWeaponRarity();
	private:
		std::string _weaponName;
		int _weaponDamage;
		std::string _weaponRarity;
	};
}