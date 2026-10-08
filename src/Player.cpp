#include "Player.h"

#include <algorithm>
#include <stdexcept>
#include <utility>

Player::Player(std::string name, int health, Weapon weapon)
    : name_(std::move(name)), health_(health), weapon_(std::move(weapon))
{
    if (health < 0)
    {
        throw std::invalid_argument("Player health cannot be negative");
    }
}

void Player::receive_damage(int damage)
{
    if (damage < 0)
    {
        throw std::invalid_argument("Damage cannot be negative");
    }

    health_ = std::max(0, health_ - damage);
}

bool Player::is_alive() const noexcept
{
    return health_ > 0;
}

int Player::health() const noexcept
{
    return health_;
}

const std::string& Player::name() const noexcept
{
    return name_;
}

void Player::attack_with_weapon(IPlayer& target)
{
    if (is_alive())
    {
        target.receive_damage(weapon_.damage());
    }
}

const Weapon& Player::weapon() const noexcept
{
    return weapon_;
}
