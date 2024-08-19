#include "BlockFactory.hpp"
#include "DBoard.hpp"
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

std::shared_ptr<DrawableBlock> BlockFactory::CreateBlock(BlockType blockType, Point2D coord, int w, int h)
{
    switch (blockType)
    {
    case BlockType::FRUIT:
        return std::make_shared<DFruit>(coord, w, h, pRenderWindow);
    case BlockType::BOARD:
        return std::make_shared<DBoard>(coord, w, h, pRenderWindow);
    }
}
void BlockFactory::SetRenderer(sf::RenderWindow *pRenderer)
{
    pRenderWindow = pRenderer;
}

std::shared_ptr<DrawableBlock> BlockFactory::CreateSnakeBodyBlock(SnakeBlockType snakeBodyType, Direction snakeDir,
                                                                  Point2D coord, int w, int h)
{
    switch (snakeBodyType)
    {
    case SnakeBlockType::HEAD:
        return std::make_shared<DSnakeBody>(coord, w, h, pRenderWindow, snakeBodyType, snakeDir);
    case SnakeBlockType::BODY:
        return std::make_shared<DSnakeBody>(coord, w, h, pRenderWindow, snakeBodyType, snakeDir);
    case SnakeBlockType::TAIL:
        return std::make_shared<DSnakeBody>(coord, w, h, pRenderWindow, snakeBodyType, snakeDir);
    }
}

} // namespace RSnakeGame
