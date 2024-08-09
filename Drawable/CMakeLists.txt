add_library(Drawable STATIC
    BlockFactory.cpp
    Collider.cpp
    DBoardWall.cpp
    DSnakeBody.cpp
    DFruit.cpp
)

target_link_libraries(Drawable 
    PRIVATE 
        sfml-graphics
)

target_include_directories(Drawable 
    PUBLIC
        "${PROJECT_SOURCE_DIR}/Drawable"
        "${PROJECT_SOURCE_DIR}/Utilities"
)
