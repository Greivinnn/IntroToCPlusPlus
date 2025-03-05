#include "Player.h"
#include "Health.h"

#include <iostream>

using namespace std;

int main()
{
    Player player("Bob");
    Health health(100);
    health.ShowHealth(player); // Friend member function allows access
    return 0;
}