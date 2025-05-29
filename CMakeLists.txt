cmake_minimum_required(VERSION 3.26)
project(SimpleCPPBattleSystem)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
    main.cpp
    Attack.cpp
    Battler.cpp
)

set(HEADER_FILES
    Attack.h
    Battler.h
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
set(CMAKE_EXE_LINKER_FLAGS "-static")