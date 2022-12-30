cmake_minimum_required(VERSION 3.13)

add_library(GameObjects STATIC
            Snake.cpp
            Board.cpp
            Fruit.cpp
            ScoreBoard.cpp)

target_link_libraries(GameObjects PRIVATE Shapes)


target_include_directories(GameObjects PUBLIC
                           "${PROJECT_SOURCE_DIR}/GameObjects"
                          )
