add_library(Shapes STATIC
    DBoardWall.cpp
    DSnakeBody.cpp
    DFruit.cpp
    BlockFactory.cpp
)

target_link_libraries(Shapes PRIVATE 
    sfml-graphics
)

target_include_directories(Shapes PUBLIC
    "${PROJECT_SOURCE_DIR}/Shapes"
)
