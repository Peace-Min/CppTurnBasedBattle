#include "Weapon.h"

#include <stdexcept>
#include <utility>

Weapon::Weapon(std::string name, int damage)
    : name_(std::move(name)), damage_(damage)
{
    if (damage < 0)
    {
        throw std::invalid_argument("Weapon damage cannot be negative");
    }
}

const std::string& Weapon::name() const noexcept
{
    return name_;
}

int Weapon::damage() const noexcept
{
    return damage_;
}
