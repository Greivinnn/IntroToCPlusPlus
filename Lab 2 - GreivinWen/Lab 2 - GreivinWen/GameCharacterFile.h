#pragma once
#include <iostream>
#include <string>

struct GameCharacter 
{
	GameCharacter(int lvl, std::string name, int hp)
	{
		level = lvl, characterName = name, health = hp;
	}
	std::string characterName;
	int health;
	int level;
};

