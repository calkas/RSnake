cmake_minimum_required(VERSION 3.13)

add_library(Control STATIC InputControl.cpp)

target_include_directories(Control PUBLIC
                           "${PROJECT_SOURCE_DIR}/Control"
                           )
