#pragma once
#include "Constans.hpp"
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
    static constexpr int SIMPLE_BLOCK_WIDTH{10};
    static constexpr int SIMPLE_BLOCK_HEIGHT{10};
    static BlockFactory *Instance();
    void SetRenderer(sf::RenderWindow *pRenderer);
    std::shared_ptr<DrawableBlock> CreateBlock(BlockType blockType, Point2D coord, int w, int h);
    std::shared_ptr<DrawableBlock> CreateSnakeBodyBlock(SnakeBlockType snakeBodyType, Direction snakeDir, Point2D coord,
                                                        int w, int h);

  private:
    BlockFactory() = default;
    sf::RenderWindow *pRenderWindow;
};
} // namespace RSnakeGame
