#include "Board.h"
#include "AObjectShape.h"
#include "DBodyBuilder.h"

namespace RSnakeGame
{

Board::Board(int height, int widht)
{
    CreateGameBoard(height,widht);
}

Board::~Board()
{
}

void Board::CreateGameBoard(const int height, const int widht)
{
    for(int lineId = 0; lineId < height; lineId++)
    {
        if(lineId == 0 || lineId == (height - 1))
        {
            for(int columnId = 0; columnId < widht; columnId++)
            {
                CreateWall(columnId,lineId);
            }
        }
        else
        {
             CreateWall(0,lineId);
             CreateWall(widht - 1 ,lineId);
        }
    }
}

void Board::Draw() const
{
    for(const auto &pWall : m_Walls)
    {
        pWall->Draw();
    }
}

bool Board::isCollision(const int x, const int y) const
{
    for(const auto &pWall : m_Walls)
    {
        if((pWall->m_posX == x) && (pWall->m_posY == y))
        {
            return true;
        }
    }
    return false;
}

void Board::CreateWall(const int x, const int y)
{
    m_Walls.push_back(CreateBoardWallShape(x, y));
}

}
