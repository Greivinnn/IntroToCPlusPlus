#pragma once
#include <string>

namespace Practice
{
	class Character
	{
	public:
		Character(std::string name, int health, int power);
		void TakeDamage(int damage);
		void Fight(Character char1, Character char2);
		void DisplayStats();
	private:
		std::string _characterName;
		int _characterHealth;
		int _attackPower;
	};
}