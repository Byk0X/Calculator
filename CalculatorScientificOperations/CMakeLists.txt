cmake_minimum_required(VERSION 3.28)
project(CalculatorScientificOperations)

set(CMAKE_CXX_STANDARD 17)

add_executable(CalculatorScientificOperations main.cpp
        Calculator.cpp
        Calculator.h
        DividingByZero.cpp
        DividingByZero.h)
