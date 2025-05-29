cmake_minimum_required(VERSION 3.31)
project(SimpleCPPBattleSystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(SimpleCPPBattleSystem main.cpp
        Attack.cpp
        Attack.h
        Battler.h
        Battler.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static")