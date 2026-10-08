#include "Battle.h"

#include <stdexcept>
#include <utility>

void Battle::add_player(std::unique_ptr<IPlayer> player)
{
    if (!player)
    {
        throw std::invalid_argument("Battle cannot own a null player");
    }
    if (completed_)
    {
        throw std::logic_error("Cannot add a player after the battle has run");
    }
    players_.push_back(std::move(player));
}

void Battle::run(std::ostream& output)
{
    if (completed_)
    {
        return;
    }
    if (players_.size() != 2)
    {
        throw std::logic_error("A battle requires exactly two players");
    }

    while (players_[0]->is_alive() && players_[1]->is_alive())
    {
        const std::size_t attacker_index = static_cast<std::size_t>(turn_count_ % 2);
        const std::size_t target_index = 1 - attacker_index;
        IPlayer& attacker = *players_[attacker_index];
        IPlayer& target = *players_[target_index];

        output << "Turn " << (turn_count_ + 1) << ": "
               << attacker.name() << " attacks " << target.name()
               << " (health before: " << target.health() << ")\n";
        attacker.attack(target);
        ++turn_count_;
    }

    output << "Winner: " << winner().name() << '\n';
    completed_ = true;
}

std::size_t Battle::player_count() const noexcept
{
    return players_.size();
}

int Battle::turn_count() const noexcept
{
    return turn_count_;
}

const IPlayer& Battle::winner() const
{
    if (!completed_ && (players_.size() != 2 || (players_[0]->is_alive() && players_[1]->is_alive())))
    {
        throw std::logic_error("The battle has not finished");
    }
    return players_[0]->is_alive() ? *players_[0] : *players_[1];
}
