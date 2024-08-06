#pragma once
#include "DrawableBlock.hpp"
#include <memory>

namespace sf
{
class RenderWindow;
}

namespace RSnakeGame
{
class BlockFactory
{
  public:
    enum class BlockType
    {
        SNAKE_BODY,
        FRUIT,
        BOARD_WALL
    };

    static const int SIMPLE_BLOCK_WIDTH = 10;
    static const int SIMPLE_BLOCK_HEIGHT = 10;
    static BlockFactory *Instance();

    std::unique_ptr<DrawableBlock> CreateBlock(BlockType blockType, Point2D coord, int w, int h);
    void SetRenderer(sf::RenderWindow *pRenderer);

  private:
    BlockFactory() = default;
    sf::RenderWindow *pRenderWindow;
};
} // namespace RSnakeGame
