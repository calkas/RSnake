cmake_minimum_required(VERSION 3.13)

set (INCLUDES_DIRS
     Engine
     "${PROJECT_SOURCE_DIR}/GameObjects"
     "${PROJECT_SOURCE_DIR}/Control"
    )

add_library(Engine STATIC Engine.cpp)


target_link_libraries(Engine PRIVATE
                      GameObjects
                      Control)

target_include_directories(Engine PUBLIC ${INCLUDE_DIRS})
