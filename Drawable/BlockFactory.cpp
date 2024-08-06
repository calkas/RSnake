#include "BlockFactory.hpp"
#include "DBoardWall.hpp"
#include "DFruit.hpp"
#include "DSnakeBody.hpp"
#include <SFML/Graphics.hpp>

namespace RSnakeGame
{
BlockFactory *BlockFactory::Instance()
{
    static BlockFactory instance;
    return &instance;
}

std::unique_ptr<DrawableBlock> BlockFactory::CreateBlock(BlockType blockType, Point2D coord, int w, int h)
{
    switch (blockType)
    {
    case BlockType::SNAKE_BODY:
        return std::make_unique<DSnakeBody>(coord, w, h, pRenderWindow);
    case BlockType::FRUIT:
        return std::make_unique<DFruit>(coord, w, h, pRenderWindow);
    case BlockType::BOARD_WALL:
        return std::make_unique<DBoardWall>(coord, w, h, pRenderWindow);
    }
}
void BlockFactory::SetRenderer(sf::RenderWindow *pRenderer)
{
    pRenderWindow = pRenderer;
}

} // namespace RSnakeGame
