cmake_minimum_required(VERSION 3.13)

add_library(Engine STATIC Engine.cpp)

target_link_libraries(Engine PRIVATE
                      GameObjects
                      Control)

target_include_directories(Engine PUBLIC
                         "${PROJECT_SOURCE_DIR}/Engine"
                         )
