cmake_minimum_required(VERSION 3.13)

project(RSnake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#find_package(GTest CONFIG REQUIRED)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

add_subdirectory(Control)
add_subdirectory(Drawable)
add_subdirectory(Engine)
add_subdirectory(GameObjects)
#add_subdirectory(Tests)

add_executable(RSnake main.cpp)

target_link_libraries(RSnake PRIVATE Control)
target_link_libraries(RSnake PRIVATE Drawable)
target_link_libraries(RSnake PRIVATE Engine)
target_link_libraries(RSnake PRIVATE GameObjects)
target_link_libraries(RSnake PRIVATE sfml-system sfml-graphics sfml-window)
