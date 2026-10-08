#pragma once

#include <string>

#include "IPlayer.h"
#include "Weapon.h"

class Player : public IPlayer
{
public:
    Player(std::string name, int health, Weapon weapon);

    void receive_damage(int damage) override;
    bool is_alive() const noexcept override;
    int health() const noexcept override;
    const std::string& name() const noexcept override;

protected:
    void attack_with_weapon(IPlayer& target);
    const Weapon& weapon() const noexcept;

private:
    std::string name_;
    int health_;
    Weapon weapon_;
};
