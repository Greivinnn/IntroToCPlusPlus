#pragma once

#include <string>
#include "Health.h"
using namespace std;

class Player
{
public:
    Player(string name);

    // Declare a specific member function as a friend
    friend void Health::ShowHealth(const Player& player);

private:
    string _playerName;
};