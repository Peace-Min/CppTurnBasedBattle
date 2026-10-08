#include "Archer.h"

#include <utility>

Archer::Archer(std::string name, int health, Weapon weapon)
    : Player(std::move(name), health, std::move(weapon))
{
}

void Archer::attack(IPlayer& target)
{
    attack_with_weapon(target);
}
