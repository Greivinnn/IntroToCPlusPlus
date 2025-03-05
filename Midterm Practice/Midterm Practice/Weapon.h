#pragma once
#include <string>

namespace RPG
{
	class Weapon
	{
	public:
		Weapon(std::string name, int damage, int level, std::string rarity);
	private:
		std::string _weaponName;
		int _weaponDamage;
		int _weaponLevel;
		std::string _weaponRarity;
	};
}