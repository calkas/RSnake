#include "Board.hpp"
#include "Collider.hpp"
#include "Constans.hpp"
#include "ObjectFactory.hpp"
#include <cassert>

namespace RSnakeGame
{
Board::Board(int height, int width) : m_height(height), m_width(width)
{
    CreateGameBoard(height, width);
}

Board::~Board()
{
}

void Board::CreateGameBoard(const int size_y, const int size_x)
{
    assert(m_height % Texture::DEFAULT_HEIGHT == 0);
    assert(m_width % Texture::DEFAULT_WIDTH == 0);

    const int numberOfHorizontalWalls = m_width / Texture::DEFAULT_WIDTH;
    const int numberOfVerticalWalls = (m_height / Texture::DEFAULT_HEIGHT) - 2;

    for (int columnId = 0; columnId < numberOfHorizontalWalls; columnId++)
    {
        CreateWallBlock(columnId * Texture::DEFAULT_WIDTH, 0);
        CreateWallBlock(columnId * Texture::DEFAULT_WIDTH, size_y - Texture::DEFAULT_WIDTH);
    }

    for (int rowId = 1; rowId <= numberOfVerticalWalls; rowId++)
    {
        CreateWallBlock(0, rowId * Texture::DEFAULT_HEIGHT);
        CreateWallBlock(size_x - Texture::DEFAULT_WIDTH, rowId * Texture::DEFAULT_HEIGHT);
    }
}

void Board::Draw() const
{
    for (const auto &pWall : m_Walls)
    {
        pWall->Draw();
    }
}

bool Board::IsCollision(std::shared_ptr<DrawableObject> object) const
{
    for (const auto &pWall : m_Walls)
    {
        if (Collider::Rectangle::isCollisionDetected(*pWall, *object))
        {
            return true;
        }
    }
    return false;
}

void Board::CreateWallBlock(const int x, const int y)
{
    m_Walls.push_back(ObjectFactory::Instance()->CreateBoardBlock(Point2D{x, y}, Texture::DEFAULT_WIDTH,
                                                                  Texture::DEFAULT_HEIGHT, 0, 1.0));
}

} // namespace RSnakeGame
