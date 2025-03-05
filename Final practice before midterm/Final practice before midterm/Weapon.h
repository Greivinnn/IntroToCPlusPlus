#pragma once
#include <string>

namespace Practice
{
	class Weapon
	{
	public:
		Weapon(std::string name, float durability, int damage, std::string rarity);
		std::string GetName();
		void printWeaponDetails();
		void useWeapon();
	public:
		std::string M_weaponName;
		float M_durability;
		int M_weaponDamage;
		std::string M_rarity;
	};
}