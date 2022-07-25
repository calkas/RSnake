cmake_minimum_required(VERSION 3.13)

set (INCLUDES_DIRS
     Shapes
    )

add_library(Shapes STATIC
            DBoardWall.cpp
            DSnakeBody.cpp
            DFruit.cpp
            DBodyBuilder.cpp)

target_include_directories(Shapes PUBLIC ${INCLUDE_DIRS})
