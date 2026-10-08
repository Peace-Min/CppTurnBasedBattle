#include <gtest/gtest.h>

#include <memory>
#include <sstream>
#include <stdexcept>

#include "Archer.h"
#include "Battle.h"
#include "Warrior.h"

TEST(BattleTest, OwnsRegisteredPlayers)
{
    Battle battle;
    battle.add_player(std::make_unique<Archer>("Archer", 10, Weapon("Bow", 3)));
    battle.add_player(std::make_unique<Warrior>("Warrior", 10, Weapon("Axe", 3)));

    EXPECT_EQ(battle.player_count(), 2U);
}

TEST(BattleTest, StopsWhenOnePlayerDies)
{
    Battle battle;
    battle.add_player(std::make_unique<Archer>("Archer", 6, Weapon("Bow", 7)));
    battle.add_player(std::make_unique<Warrior>("Warrior", 5, Weapon("Axe", 5)));
    std::ostringstream output;

    battle.run(output);

    EXPECT_EQ(battle.turn_count(), 1);
    EXPECT_EQ(battle.winner().name(), "Archer");
    EXPECT_NE(output.str().find("Winner: Archer"), std::string::npos);
    EXPECT_EQ(output.str().find("Turn 2"), std::string::npos);
}

TEST(BattleTest, RequiresExactlyTwoPlayers)
{
    Battle battle;
    std::ostringstream output;

    EXPECT_THROW(battle.run(output), std::logic_error);
}
