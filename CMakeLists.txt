cmake_minimum_required(VERSION 3.20)
project(CppTurnBasedBattle LANGUAGES CXX)

if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(BattleCore
    src/Archer.cpp
    src/Battle.cpp
    src/Player.cpp
    src/Warrior.cpp
    src/Weapon.cpp
)
target_include_directories(BattleCore PUBLIC include)

add_executable(BattleApp app/main.cpp)
target_link_libraries(BattleApp PRIVATE BattleCore)

include(FetchContent)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(BattleTests
    tests/BattleTests.cpp
    tests/PlayerTests.cpp
    tests/WeaponTests.cpp
)
target_link_libraries(BattleTests PRIVATE BattleCore GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(BattleTests)
