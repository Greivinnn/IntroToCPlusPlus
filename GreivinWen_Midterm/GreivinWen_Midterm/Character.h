#pragma once
#include <string>
#include "Inventory.h"

namespace Midterm
{
	class Character
	{
	public:
		Character(std::string name, int health, int attackPower, int defence);
		void takeDamage(int amount);
		void AttackFunction(Character* target);
		void DisplayStats();
		void BattleFunction(Character* player1, Character* player2);
		void AddItemToInvetory(Weapon weapon);
		void UseItemFromInventory(std::string item);
		void PrintInvetory();
		void UseMedkit();
		int GetDamage();
		int GetHealth();
		std::string GetName();
	private:
		std::string _characterName;
		int _characterHealth;
		int _characterAttackPower;
		int _characterDefence;
		Inventory _inventory;
	};
}