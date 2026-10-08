#pragma once

#include <string>

#include "Player.h"

class Warrior final : public Player
{
public:
    Warrior(std::string name, int health, Weapon weapon);
    void attack(IPlayer& target) override;
};
