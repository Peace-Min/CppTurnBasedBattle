#pragma once

#include <string>

class Weapon
{
public:
    Weapon(std::string name, int damage);

    const std::string& name() const noexcept;
    int damage() const noexcept;

private:
    std::string name_;
    int damage_;
};
