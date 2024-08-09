
add_executable(UT SnakeTest.cpp FruitTest.cpp BoardTest.cpp)

target_link_libraries(UT 
    PRIVATE
        Drawable
        GameObjects 
        GTest::gtest
        GTest::gtest_main
        GTest::gmock
        GTest::gmock_main
)

target_include_directories(UT 
    PRIVATE 
        "${PROJECT_SOURCE_DIR}/Drawable"
        "${PROJECT_SOURCE_DIR}/Utilities"
        "${PROJECT_SOURCE_DIR}/UT"
)

gtest_add_tests(TARGET UT)
