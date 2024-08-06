add_library(Engine STATIC Engine.cpp)

target_link_libraries(Engine PRIVATE
  Drawable
  GameObjects
  Control
  sfml-system
  sfml-graphics
  sfml-window
)

target_include_directories(Engine PUBLIC
  "${PROJECT_SOURCE_DIR}/Engine"
)
