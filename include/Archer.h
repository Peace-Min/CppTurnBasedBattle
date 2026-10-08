#pragma once

#include <string>

#include "Player.h"

class Archer final : public Player
{
public:
    Archer(std::string name, int health, Weapon weapon);
    void attack(IPlayer& target) override;
};
