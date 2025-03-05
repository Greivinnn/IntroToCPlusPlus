#pragma once

#include <string>
using namespace std;

class Game; // Forward declaration

class Player
{
public:
    Player(string name);

    void DisplayGameName(const Game& game);

private:
    string _playerName;
};