#include <gtest/gtest.h>

#include <stdexcept>

#include "Archer.h"
#include "Warrior.h"

TEST(PlayerTest, ReducesHealthButNeverBelowZero)
{
    Warrior warrior("Warrior", 10, Weapon("Axe", 3));

    warrior.receive_damage(4);
    EXPECT_EQ(warrior.health(), 6);

    warrior.receive_damage(100);
    EXPECT_EQ(warrior.health(), 0);
    EXPECT_FALSE(warrior.is_alive());
}

TEST(PlayerTest, RejectsNegativeInitialHealth)
{
    EXPECT_THROW(Warrior("Warrior", -1, Weapon("Axe", 3)), std::invalid_argument);
}

TEST(PlayerTest, ArcherAndWarriorShareTheSameInterface)
{
    Archer archer("Archer", 20, Weapon("Bow", 7));
    Warrior warrior("Warrior", 20, Weapon("Axe", 5));
    IPlayer& attacker = archer;

    attacker.attack(warrior);

    EXPECT_EQ(warrior.health(), 13);
}

TEST(PlayerTest, DeadPlayerCannotAttack)
{
    Warrior dead_warrior("Warrior", 1, Weapon("Axe", 5));
    Archer target("Archer", 20, Weapon("Bow", 7));
    dead_warrior.receive_damage(1);

    dead_warrior.attack(target);

    EXPECT_EQ(target.health(), 20);
}
