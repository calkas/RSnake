
add_executable(UT SnakeTest.cpp FruitTest.cpp BoardTest.cpp)

target_link_libraries(UT 
    PRIVATE
        GameObjects
        GTest::gtest
        GTest::gtest_main
        GTest::gmock
        GTest::gmock_main
        # this stuff is needed for the OpenGL context on github actions :(
        ${OPENGL_gl_LIBRARY}
        ${CMAKE_DL_LIBS}
        X11
        Xrandr
        GL
        GLU
)

target_include_directories(UT 
    PRIVATE 
        "${PROJECT_SOURCE_DIR}/Drawable"
        "${PROJECT_SOURCE_DIR}/Utilities"
        "${PROJECT_SOURCE_DIR}/UT"
)

gtest_discover_tests(UT)
