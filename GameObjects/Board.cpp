#include "Board.hpp"
#include "Collider.hpp"
#include "Constans.hpp"
#include "ObjectFactory.hpp"
#include <cassert>

namespace RSnakeGame
{
Board::Board()
{
    CreateGameBoard();
}

void Board::CreateGameBoard()
{
    const int col = Resolution::BOARD_WIDTH / Texture::DEFAULT_WIDTH;
    const int row = Resolution::BOARD_HEIGHT / Texture::DEFAULT_HEIGHT;

    for (int i = 0; i <= col; i++)
    {
        for (int j = 0; j <= row; j++)
        {
            CreateBlock(i * Texture::DEFAULT_WIDTH, j * Texture::DEFAULT_HEIGHT);
        }
    }
}

void Board::Draw() const
{
    for (const auto &pBlock : gameMap)
    {
        pBlock->Draw();
    }
}

bool Board::IsCollision(std::shared_ptr<DrawableObject> object) const
{
    bool outOfBoardX = object->position.x <= 0 || object->position.x >= Resolution::BOARD_WIDTH;
    bool outOfBoardY = object->position.y <= 0 || object->position.y >= Resolution::BOARD_HEIGHT;

    return outOfBoardX || outOfBoardY;
}

void Board::CreateBlock(const int x, const int y)
{
    gameMap.push_back(ObjectFactory::Instance()->CreateBoardBlock(
        Texture::GRASS_1, Point2D{x, y}, Texture::DEFAULT_WIDTH, Texture::DEFAULT_HEIGHT, 0, 1.0));
}

} // namespace RSnakeGame
