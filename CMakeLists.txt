cmake_minimum_required(VERSION 2.6)

project(RSnake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#Bring the headers into the project
#include_directories(include)

set(SOURCES
    main.cpp
    Snake.cpp
    Engine.cpp
    Board.cpp
    Fruit.cpp
    DBoardWall.cpp
    DSnakeBody.cpp
    DFruit.cpp
    InputControl.cpp)

#However, the file(GLOB...) allows for wildcard additions:
#file(GLOB SOURCES "src/*.cpp")

add_executable(RSnake ${SOURCES})

