#include "Board.hpp"
#include "BlockFactory.hpp"
#include "Collider.hpp"
#include "DBoardWall.hpp"
#include <cassert>

namespace RSnakeGame
{

const int BOARD_WALL_WIDTH = BlockFactory::SIMPLE_BLOCK_WIDTH;
const int BOARD_WALL_HEIGHT = BlockFactory::SIMPLE_BLOCK_HEIGHT;

Board::Board(int height, int width) : m_height(height), m_width(width)
{
    CreateGameBoard(height, width);
}

Board::~Board()
{
}

void Board::CreateGameBoard(const int size_y, const int size_x)
{
    assert(m_height % BOARD_WALL_HEIGHT == 0);
    assert(m_width % BOARD_WALL_WIDTH == 0);

    const int numberOfHorizontalWalls = m_width / BOARD_WALL_WIDTH;
    const int numberOfVerticalWalls = (m_height / BOARD_WALL_HEIGHT) - 2;

    for (int columnId = 0; columnId < numberOfHorizontalWalls; columnId++)
    {
        CreateWallBlock(columnId * BOARD_WALL_WIDTH, 0);
        CreateWallBlock(columnId * BOARD_WALL_WIDTH, size_y - BOARD_WALL_WIDTH);
    }

    for (int rowId = 1; rowId <= numberOfVerticalWalls; rowId++)
    {
        CreateWallBlock(0, rowId * BOARD_WALL_HEIGHT);
        CreateWallBlock(size_x - BOARD_WALL_WIDTH, rowId * BOARD_WALL_HEIGHT);
    }
}

void Board::Draw() const
{
    for (const auto &pWall : m_Walls)
    {
        pWall->Draw();
    }
}

bool Board::IsCollision(std::shared_ptr<DrawableBlock> object) const
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
    m_Walls.push_back(BlockFactory::Instance()->CreateBlock(BlockFactory::BlockType::BOARD_WALL, Point2D{x, y},
                                                            BOARD_WALL_WIDTH, BOARD_WALL_HEIGHT));
}

} // namespace RSnakeGame
