#pragma once

#include <string>

class IPlayer
{
public:
    virtual ~IPlayer() = default;

    virtual void attack(IPlayer& target) = 0;
    virtual void receive_damage(int damage) = 0;
    virtual bool is_alive() const noexcept = 0;
    virtual int health() const noexcept = 0;
    virtual const std::string& name() const noexcept = 0;
};
