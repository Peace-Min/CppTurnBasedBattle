#include <iostream>
#include <memory>

#include "Archer.h"
#include "Battle.h"
#include "Warrior.h"

int main()
{
    Battle battle;
    battle.add_player(std::make_unique<Archer>("Archer", 30, Weapon("Bow", 7)));
    battle.add_player(std::make_unique<Warrior>("Warrior", 25, Weapon("Axe", 5)));

    battle.run(std::cout);
}
