cmake_minimum_required(VERSION 2.6)

project(RSnake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Bring the headers into the project

set(INCLUDE_DIRECTORIES
    Control
    DrawShapes
    Engine
    GameObjects)

include_directories(${INCLUDE_DIRECTORIES})

#include_directories(Control)
#include_directories(DrawShapes)
#include_directories(Engine)
#include_directories(GameObjects)

set(SOURCES
    main.cpp
    Control/InputControl.cpp
    DrawShapes/DBoardWall.cpp
    DrawShapes/DSnakeBody.cpp
    DrawShapes/DFruit.cpp
    DrawShapes/DBodyBuilder.cpp
    Engine/Engine.cpp
    GameObjects/Snake.cpp
    GameObjects/Board.cpp
    GameObjects/Fruit.cpp
    GameObjects/ScoreBoard.cpp)

#However, the file(GLOB...) allows for wildcard additions:
#file(GLOB SOURCES "src/*.cpp")

add_executable(RSnake ${SOURCES})
