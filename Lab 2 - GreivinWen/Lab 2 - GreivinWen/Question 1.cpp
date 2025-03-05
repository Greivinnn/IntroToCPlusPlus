#include <iostream>
#include "GameCharacterFile.h"
#include <array>



void CalculateHealthAvg(std::array<GameCharacter, 3> gameCharaters)
{
    int average;
    int sum = 0;

    for (int i = 0; i < 3; i++)
    {
        sum = sum + gameCharaters[i].health;
    }
    average = sum / 3;

    std::cout << "The age average health of all characters is: " << average;
}

void DisplayGameCharacters(std::array<GameCharacter, 3> gameCharacters)
{
    for (GameCharacter gc : gameCharacters)
    {
        std::cout << "Character Level: " << gc.level << "\n";
        std::cout << "Character Name: " << gc.characterName << "\n";
        std::cout << gc.characterName << "'s Health: " << gc.health << "\n\n";
    }
}

int main()
{
    std::array<GameCharacter, 3> players =
    {
        GameCharacter(4, "David", 100),
        GameCharacter(7, "Juan", 500),
        GameCharacter(1, "Santi", 25),
    };

    DisplayGameCharacters(players);
    CalculateHealthAvg(players);
}
