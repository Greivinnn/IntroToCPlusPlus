#pragma once

class Player; // Forward declaration

class Health
{
public:
    Health(int hp);

    void ShowHealth(const Player& player);

private:
    int _healthPoints;
};