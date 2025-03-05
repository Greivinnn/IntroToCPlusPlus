#pragma once
#include <string>
#include <iostream>

namespace Practice
{
	class Player
	{
	public:
		Player(std::string name, int health, int mana)
			:_name(name), _health(health), _mana(mana)
		{
		}
		std::string GetName()
		{
			return _name;
		}
		int getHealth() const
		{
			return _health;
		}
		int getMana() const
		{
			return _mana;
		}
		void setHealth(int health)
		{
			_health = health;
		}
		void setMana(int mana)
		{
			_mana = mana;
		}
		void printStats() const
		{
			std::cout << "Player Name: " << _name << "\nHealth: " << _health << "\nMana: " << _mana << "\n\n";
		}
	private:
		std::string _name;
		int _health;
		int _mana;
	};
}