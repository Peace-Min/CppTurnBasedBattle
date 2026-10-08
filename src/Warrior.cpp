#include "Warrior.h"

#include <utility>

Warrior::Warrior(std::string name, int health, Weapon weapon)
    : Player(std::move(name), health, std::move(weapon))
{
}

void Warrior::attack(IPlayer& target)
{
    attack_with_weapon(target);
}
