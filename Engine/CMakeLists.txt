cmake_minimum_required(VERSION 3.13)

add_library(Engine Engine.cpp)


target_link_libraries(Engine PUBLIC
                      GameObjects
                      Control)

target_include_directories(Engine PUBLIC
                           "${PROJECT_SOURCE_DIR}/GameObjects"
                           "${PROJECT_SOURCE_DIR}/Control")
