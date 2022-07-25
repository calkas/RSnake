cmake_minimum_required(VERSION 3.13)

set (INCLUDES_DIRS
     Control
    )
add_library(Control STATIC InputControl.cpp)

target_include_directories(Control PUBLIC ${INCLUDE_DIRS})
