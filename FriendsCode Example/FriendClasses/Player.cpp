#include "Player.h"
#include "Game.h"
#include <iostream>

Player::Player(string name) :
    _playerName(name)
{
}

void Player::DisplayGameName(const Game& game)
{
    // Accessing private member of Game class
    cout << "Player " << _playerName << " is playing " << game._gameName << endl;
}