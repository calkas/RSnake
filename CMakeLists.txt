cmake_minimum_required(VERSION 3.13)

project(RSnake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#Hack for VS for dynamic linking
set(gtest_force_shared_crt ON CACHE BOOL "Always use msvcrt.dll" FORCE)

enable_testing()

add_subdirectory(Control)
add_subdirectory(Shapes)
add_subdirectory(Engine)
add_subdirectory(GameObjects)
add_subdirectory(Tests)

add_executable(RSnake main.cpp)

target_link_libraries(RSnake PRIVATE Control)
target_link_libraries(RSnake PRIVATE Shapes)
target_link_libraries(RSnake PRIVATE Engine)
target_link_libraries(RSnake PRIVATE GameObjects)
