cmake_minimum_required(VERSION 4.3)
project(Lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab3 main.cpp
        Exercice1/Student.cpp
        Exercice1/Student.h
        Exercise2/Course.cpp
        Exercise2/Course.h
        Exercise3/ScoreTable.cpp
        Exercise3/ScoreTable.h
)
