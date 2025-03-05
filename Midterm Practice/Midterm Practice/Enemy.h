#pragma once
#include <string>

namespace RPG
{
	class Enemy
	{
	public:
		Enemy(std::string type, int health, int damage);

		void PrintEnemyDetails();

	private:
		std::string _type;
		int _health;
		int _damage;
	};
}
