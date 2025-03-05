#pragma once
#include <string>

namespace Practice
{
	class Character
	{
	public:
		Character(std::string name, int health, int damage);

		void TakeDamage(int amount);

		void PrintStats();

		int GetDamage();

	private:
		std::string _name;
		int _health;
		int _damage;
	};
}