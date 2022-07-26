cmake_minimum_required(VERSION 3.13)

project(unit_tests)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

add_executable(ut_gameobjects_tests GameObjectsTest.cpp)

target_link_libraries(ut_gameobjects_tests gtest gmock gtest_main GameObjects)
