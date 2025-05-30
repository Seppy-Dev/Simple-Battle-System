cmake_minimum_required(VERSION 3.26)
project(SimpleCPPBattleSystem)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
        main.cpp
        Attack.cpp
        Battler.cpp
        Heal.cpp
        Meditate.cpp
)

set(HEADER_FILES
        Attack.h
        Battler.h
        Heal.h
        Meditate.h
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
set(CMAKE_EXE_LINKER_FLAGS "-static")