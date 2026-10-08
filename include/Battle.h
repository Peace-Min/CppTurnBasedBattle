#pragma once

#include <cstddef>
#include <memory>
#include <ostream>
#include <vector>

#include "IPlayer.h"

class Battle
{
public:
    void add_player(std::unique_ptr<IPlayer> player);
    void run(std::ostream& output);

    std::size_t player_count() const noexcept;
    int turn_count() const noexcept;
    const IPlayer& winner() const;

private:
    std::vector<std::unique_ptr<IPlayer>> players_;
    int turn_count_ = 0;
    bool completed_ = false;
};
