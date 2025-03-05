#pragma once

#include <string>
using namespace std;

class Player; // Forward declaration

class Game
{
public:
    Game(string name);

    // Declare Player as a friend class
    friend class Player;

private:
    string _gameName;
};