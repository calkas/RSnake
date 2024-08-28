#pragma once
#include <cstdint>
namespace RSnakeGame
{

constexpr bool DEBUG_MODE{false};

union RGBColor {
    struct
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };
    uint32_t color;

    constexpr RGBColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255)
        : r(red), g(green), b(blue), a(alpha)
    {
    }
};

constexpr RGBColor UI_COLOR{79, 70, 13};

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
constexpr const char *UI_FRAME{"ui_frame"};
constexpr const char *UI_GAME_OVER{"ui_game_over"};

constexpr int DEFAULT_WIDTH{50};
constexpr int DEFAULT_HEIGHT{50};

} // namespace Texture

namespace Font
{
constexpr const char *PATH{"./Assets/Fonts/"};
constexpr const char *GLOBAL{"global"};
constexpr unsigned int DEFAULT_SIZE{24};
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
