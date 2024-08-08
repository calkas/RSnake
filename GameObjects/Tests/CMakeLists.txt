
add_executable(SnakeTests SnakeTests.cpp)

target_link_libraries(SnakeTests PRIVATE GameObjects GTest::gtest GTest::gtest_main)

target_include_directories(SnakeTests PRIVATE "${PROJECT_SOURCE_DIR}/Drawable")

gtest_add_tests(TARGET SnakeTests)
