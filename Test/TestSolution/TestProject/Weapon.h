#pragma once
#include <string>

namespace Practice
{
	class Weapon
	{
	public:
		Weapon(std::string name, int damage, std::string rarity);

		void PrintWeaponDetails();

		void IncreaseDamageByPercent(int damagePercent);

		std::string GetName();

	private:
		std::string _name;
		int _damage;
		std::string _rarity;
	};
}