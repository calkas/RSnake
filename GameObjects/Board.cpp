#include "Board.h"
#include "AObjectShape.h"
#include "DBodyBuilder.h"
#include <iostream>

namespace RSnakeGame
{

Board::Board(int height, int widht)
{
    CreateGameBoard(height,widht);
}

Board::~Board()
{
    for(auto &pWallElement : m_VecOfBoardWalls)
    {
        delete pWallElement;
        pWallElement = nullptr;
    }
    m_VecOfBoardWalls.clear();
}

void Board::CreateGameBoard(int height, int widht)
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

void Board::Draw()
{
    for(const auto &pWallElement : m_VecOfBoardWalls)
    {
        pWallElement->Draw();
    }
}

void Board::printAllCoord()
{
    int i = 0;
    for(const auto &pWallElement : m_VecOfBoardWalls)
    {
        std::cout<<i<<")"<< pWallElement->m_posX<< "," <<pWallElement->m_posY <<std::endl;
        ++i;
    }
}

bool Board::isCollision(int x, int y)
{
    for(const auto &pWallElement : m_VecOfBoardWalls)
    {
        if((pWallElement->m_posX == x) && (pWallElement->m_posY == y))
        {
            return true;
        }
    }
    return false;
}

void Board::CreateWall(int x, int y)
{
    AObjectShape *pWallObj = CreateBoardWallShape(x, y);
    m_VecOfBoardWalls.push_back(pWallObj);
}

}
