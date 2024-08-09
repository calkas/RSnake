cmake_minimum_required(VERSION 3.24)

project(RSnake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GoogleTest)
enable_testing()

find_package(GTest CONFIG REQUIRED)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)


file(COPY ${CMAKE_CURRENT_LIST_DIR}/Assets/Fonts/
     DESTINATION ${CMAKE_BINARY_DIR}/Assets/Fonts/)

add_subdirectory(Control)
add_subdirectory(Drawable)
add_subdirectory(Engine)
add_subdirectory(GameObjects)

add_executable(RSnake main.cpp)

target_link_libraries(RSnake 
     PRIVATE 
          Control
          Drawable
          Engine
          GameObjects
)

target_link_libraries(RSnake 
     PRIVATE
          sfml-system 
          sfml-graphics 
          sfml-window
)
