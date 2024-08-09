add_library(GameObjects STATIC
    Snake.cpp
    Board.cpp
    Fruit.cpp
    ScoreBoard.cpp
)
target_include_directories(GameObjects 
    PUBLIC
        "${PROJECT_SOURCE_DIR}/GameObjects"
)

target_link_libraries(GameObjects 
    PRIVATE 
        Drawable
)

add_subdirectory(UT)
