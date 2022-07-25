cmake_minimum_required(VERSION 3.13)

set (INCLUDES_DIRS
     GameObjects
     "${PROJECT_SOURCE_DIR}/Shapes"
    )

add_library(GameObjects STATIC
            Snake.cpp
            Board.cpp
            Fruit.cpp
            ScoreBoard.cpp)

target_link_libraries(GameObjects PRIVATE Shapes)

target_include_directories(GameObjects PUBLIC ${INCLUDE_DIRS})
