#include <gtest/gtest.h>

#include <stdexcept>

#include "Weapon.h"

TEST(WeaponTest, StoresNameAndDamage)
{
    const Weapon weapon("Bow", 7);

    EXPECT_EQ(weapon.name(), "Bow");
    EXPECT_EQ(weapon.damage(), 7);
}

TEST(WeaponTest, RejectsNegativeDamage)
{
    EXPECT_THROW(Weapon("Broken", -1), std::invalid_argument);
}
