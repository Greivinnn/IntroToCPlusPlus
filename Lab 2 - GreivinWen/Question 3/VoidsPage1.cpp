#include <iostream>
#include <string>
#include <array>
#include "Player.h"
#include "Weapon.h"

using namespace PlayerInfo;
using namespace WeaponInfo;

Player::Player(std::string name, int score, std::array<Weapon, 3> inventory)
    : M_playerName(name), M_playerScore(score), M_playerInventory(inventory)
{

}

void Player::DisplayPlayerStuff()
{
    std::cout << "Player Name: " << M_playerName << "\n";
    std::cout << "Player Score: " << M_playerScore << "\n";
}

void Player::IncreaseScore()
{
    
    for (int i = 0; i < M_playerInventory.size(); i++)
    {
        M_playerScore += M_playerInventory[i].GetDamage();
    }
    std::cout << "Your new weapon damage is: " << M_playerScore << "\n";
    std::cout << "\n";

    
}