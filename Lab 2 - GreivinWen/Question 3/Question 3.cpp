#include <iostream>
#include <string>
#include <array>
#include "Player.h"
#include "Weapon.h"

using namespace PlayerInfo;

int main()
{
    std::array<Weapon, 3> weapons =
    {
        Weapon("Sword", 10, 15),
        Weapon("Lance", 5, 10),
        Weapon("Stick", 7, 11),
    };

    std::array<Player, 1> player1 =
    {
        Player("Juan", 20, weapons)
    };

    for (Player list : player1)
    {
        list.DisplayPlayerStuff();
    }

    std::cout << "\nInventory:\n\n";
    for (Weapon list : weapons)
    {
        list.DisplayAllWeapons();
    }

    for (Player list : player1)
    {
        list.IncreaseScore();
    }
}
