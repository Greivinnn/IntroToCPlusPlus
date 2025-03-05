#include "Player.h"
#include "Game.h"
#include <iostream>

using namespace FriendExample;

Player::Player(std::string name)
	: _playerName(name)
{
}

void Player::DisplayGameName(Game game)
{
	std::cout << "Player: " << _playerName << " is playing " << game._gameName << "\n";
}