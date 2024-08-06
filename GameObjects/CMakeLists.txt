add_library(GameObjects STATIC
    Snake.cpp
    Board.cpp
    Fruit.cpp
    ScoreBoard.cpp
)

target_link_libraries(GameObjects PRIVATE Drawable)

target_include_directories(GameObjects PUBLIC
    "${PROJECT_SOURCE_DIR}/GameObjects"
    "${PROJECT_SOURCE_DIR}/Utilities"
)
