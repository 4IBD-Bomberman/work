cmake_minimum_required(VERSION 3.10)
project(MJ)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(MJ
        Bombe.cpp
        Bombe.h
        Case.cpp
        Case.h
        Item.cpp
        Item.h
        MJ.cpp
        Mur.cpp
        Mur.h
        Plateau.cpp
        Plateau.h)
