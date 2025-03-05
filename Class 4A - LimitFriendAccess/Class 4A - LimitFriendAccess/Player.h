#pragma once
#include <string>
#include "Health.h"

class Player
{
public:
	Player(std::string name);

	friend void Health::ShowHealth(Player& name);

private:
	std::string _playerName;
};