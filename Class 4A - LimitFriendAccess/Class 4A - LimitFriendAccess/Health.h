#pragma once

class Player;

class Health
{
public:
	Health(int hp);
	void ShowHealth(Player& player);

private:
	int _healthNumber;
};