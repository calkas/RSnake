#pragma once
namespace RSnakeGame
{

constexpr const char *TITLE{"RSnake"};

namespace Texture
{
constexpr const char *PATH{"./Assets/Textures/"};
constexpr const char *SNAKE_HEAD{"snake_head"};
constexpr const char *SNAKE_BODY{"snake_body"};
constexpr const char *SNAKE_TAIL{"snake_tail"};
constexpr const char *FRUIT{"fruit"};
constexpr const char *GRASS_1{"grass1"};
constexpr const char *GRASS_2{"grass2"};

constexpr const int DEFAULT_WIDTH{50};
constexpr const int DEFAULT_HEIGHT{50};

} // namespace Texture

namespace Font
{
constexpr const char *PATH{"./Assets/Fonts/"};
constexpr const char *GLOBAL{"global"};
} // namespace Font

namespace Resolution
{
constexpr int BOARD_WIDTH{800};
constexpr int BOARD_HEIGHT{700};
} // namespace Resolution

enum class Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

enum class SnakeBlockType
{
    HEAD,
    BODY,
    TAIL
};

} // namespace RSnakeGame
