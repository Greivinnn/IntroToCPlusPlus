#pragma once

#include <iostream>
#include <string>
#include <array>
#include "Weapon.h"

using namespace WeaponInfo;

namespace PlayerInfo
{
	class Player
	{
	public:
		Player(std::string name, int score, std::array<Weapon, 3> inventory);
		void DisplayPlayerStuff();
		void IncreaseScore();
	private:
		std::string M_playerName;
		int M_playerScore;
		std::array<Weapon, 3> M_playerInventory;
	};

}