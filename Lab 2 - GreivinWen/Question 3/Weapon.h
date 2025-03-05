#pragma once

#include <iostream>
#include <string>

namespace WeaponInfo
{
	class Weapon
	{
	public:
		Weapon(std::string name, int dmg, int dur);


		void DisplayAllWeapons();
		void DecreaseDurability();
		int GetDamage();

	private:
		std::string M_weaponName;
		int M_weaponDamage;
		int M_weaponDurability;
	};
}
