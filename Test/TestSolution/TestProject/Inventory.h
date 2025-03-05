#pragma once
#include <vector>
#include "Weapon.h"

namespace Practice
{
	class Inventory
	{
	public:
		Inventory();

		void AddWeapon(Weapon newWeapon);
		void RemoveWeapon(std::string weaponName);

		void PrintInventory();

	private:
		std::vector<Weapon> _weapons;
	};
}