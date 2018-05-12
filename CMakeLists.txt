cmake_minimum_required(VERSION 3.10)
project(work)

set(CMAKE_CXX_STANDARD 11)

include_directories(MJ)

add_executable(work
        GD/GameDispatcher.py
        IA/IA.cpp
        MJ/Bombe.cpp
        MJ/Bombe.h
        MJ/MJ.cpp
        MJ/Case.cpp
        MJ/Case.h
        MJ/Item.cpp
        MJ/Item.h
        MJ/Mur.cpp
        MJ/Mur.h
        MJ/Plateau.cpp
        MJ/Plateau.h)
