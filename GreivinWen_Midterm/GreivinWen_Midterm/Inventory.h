#pragma once
#include <vector>
#include "Weapon.h"

namespace Midterm
{
	class Character;

	class Inventory
	{
	public:
		Inventory();
		void AddItem(Weapon newWeapon);
		void UseItem(std::string name);
		void displayInventory();
		void CharacterBattleFunction(Character* player1, Character* player2);
	private:
		std::vector<Weapon> _weapons;
	};
}