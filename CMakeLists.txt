cmake_minimum_required(VERSION 3.26)
project(SimpleCPPBattleSystem)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
        src/main.cpp
        src/entities/Battler.cpp
        src/battle/BattleMenu.cpp
        src/battle/BattleManager.cpp
        src/actions/Action.cpp
)

set(HEADER_FILES
        src/entities/Battler.h
        src/battle/BattleMenu.h
        src/battle/BattleManager.h
        src/actions/Action.h
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
set(CMAKE_EXE_LINKER_FLAGS "-static")

include_directories(include)