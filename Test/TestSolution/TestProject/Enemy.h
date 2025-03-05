#pragma once
#include <string>

namespace Practice
{
	class Enemy
	{
	public:
		Enemy(std::string type, int health, int damage);

		void PrintEnemyDetails();

		void TakeDamage(int amount);

	private:
		std::string _type;
		int _health;
		int _damage;
	};
}