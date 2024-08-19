#pragma once
namespace RSnakeGame
{

constexpr const char *TITLE{"RSnake"};

namespace Texture
{
constexpr const char *PATH{"./Assets/Fonts/"};
constexpr const char *SNAKE_HEAD{"snake_head"};
constexpr const char *SNAKE_BODY{"snake_body"};
constexpr const char *SNAKE_TAIL{"snake_tail"};
constexpr const char *FRUIT{"fruit"};
constexpr const char *BOARD{"board"};

} // namespace Texture

namespace Font
{
constexpr const char *PATH{"./Assets/Fonts/"};
constexpr const char *GLOBAL{"global"};
} // namespace Font

namespace Resolution
{
constexpr int WIDTH{600};
constexpr int HEIGHT{400};
} // namespace Resolution

enum class Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

enum class BlockType
{
    FRUIT,
    BOARD
};

enum class SnakeBlockType
{
    HEAD,
    BODY,
    TAIL
};

} // namespace RSnakeGame
