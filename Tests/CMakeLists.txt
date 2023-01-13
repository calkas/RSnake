# By default, new Visual Studio projects link the C runtimes dynamically but GoogleTest links them statically. 
set(gtest_force_shared_crt on)
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

add_test(gameobjects_gtests ut_gameobjects_tests)
