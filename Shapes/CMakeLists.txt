add_library(Shapes STATIC
    DBoardWall.cpp
    DSnakeBody.cpp
    DFruit.cpp
)

target_include_directories(Shapes PUBLIC
    "${PROJECT_SOURCE_DIR}/Shapes"
)
