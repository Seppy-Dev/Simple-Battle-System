cmake_minimum_required(VERSION 3.31)
project(BeanVSCheese)

set(CMAKE_CXX_STANDARD 20)

add_executable(BeanVSCheese main.cpp
        SkyesRandomStuff/RandomNumber.cpp
        SkyesRandomStuff/RandomNumber.h)
set(CMAKE_EXE_LINKER_FLAGS "-static")