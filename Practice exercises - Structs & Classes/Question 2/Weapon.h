#pragma once
#include <string>

namespace WeaponInfo
{
	class Weapon
	{
	public:
		Weapon(std::string name, int damage, std::string rarity);
		void printWeaponDetails();
		void IncreaseDamage();

	public:
		std::string M_weaponName;
		int M_weaponDamage;
		std::string M_rarity;
	};
}