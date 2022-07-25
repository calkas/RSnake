cmake_minimum_required(VERSION 3.13)

project(RSnake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Control)
add_subdirectory(Shapes)
add_subdirectory(Engine)
add_subdirectory(GameObjects)

#However, the file(GLOB...) allows for wildcard additions:
#file(GLOB SOURCES "src/*.cpp")

add_executable(RSnake main.cpp)

target_link_libraries(RSnake PRIVATE Control)
target_link_libraries(RSnake PRIVATE Shapes)
target_link_libraries(RSnake PRIVATE Engine)
target_link_libraries(RSnake PRIVATE GameObjects)

target_include_directories(Control PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/Control"
                           )
target_include_directories(Shapes PUBLIC
                           "${PROJECT_SOURCE_DIR}/Shapes"
                           )
target_include_directories(Engine PUBLIC
                           "${PROJECT_SOURCE_DIR}/Engine"
                           )
target_include_directories(GameObjects PUBLIC
                           "${PROJECT_SOURCE_DIR}/GameObjects"
                          )
