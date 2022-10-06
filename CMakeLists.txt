cmake_minimum_required(VERSION 3.20)
project(Open_Ended_Project1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Open_Ended_Project1
        Card.cpp
        Card.h
        Holdem.cpp
        Holdem.h
        Player.cpp
        Player.h
        main.cpp)
add_executable(Testing
        Card.cpp
        Card.h
        Holdem.cpp
        Holdem.h
        Player.cpp
        Player.h
        testing.cpp)
