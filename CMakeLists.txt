cmake_minimum_required(VERSION 3.26)
project(SimpleCPPBattleSystem)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
        main.cpp
        src/actions/Attack.cpp
        src/entities/Battler.cpp
        src/actions/Heal.cpp
        src/actions/Recover.cpp
)

set(HEADER_FILES
        src/actions/Attack.h
        src/entities/Battler.h
        src/actions/Heal.h
        src/actions/Recover.h
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
set(CMAKE_EXE_LINKER_FLAGS "-static")