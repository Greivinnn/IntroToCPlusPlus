#pragma once
#include <string>
#include <array>
#include "Weapon.h"

namespace Practice	
{
	class Character
	{
	public:
		Character(std::string name, int health, int level);
		void PrintStats();
	private:
		std::string M_name;
		int M_health;
		int M_level;
	};
}