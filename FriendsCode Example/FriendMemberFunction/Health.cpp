#include "Health.h"
#include "Player.h"
#include <iostream>

using namespace std;

Health::Health(int hp) :
    _healthPoints(hp)
{
}

void Health::ShowHealth(const Player& player)
{
    cout << "Player " << player._playerName << " has " << _healthPoints << " health points." << endl;
}