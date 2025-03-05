#pragma once
#include <string>

namespace CharacterInfo
{
	class Character
	{
	public:
		Character(std::string name, int health, int damage);
		void TakeDamage(int damageAmount);
		void PrintStats();
		int GetDamage();
	private:
		std::string M_characterName;
		int M_health;
		int M_damage;
	};
}