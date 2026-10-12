cmake_minimum_required(VERSION 3.20)
project(CppTurnBasedBattle LANGUAGES CXX)

if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# T01부터 문서의 순서대로 BattleCore, BattleApp, BattleTests를 추가합니다.
