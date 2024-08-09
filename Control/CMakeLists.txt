add_library(Control STATIC InputControl.cpp)

target_link_libraries(Control
    PRIVATE
      sfml-window
)

target_include_directories(Control
    PUBLIC
      "${PROJECT_SOURCE_DIR}/Control"
)
