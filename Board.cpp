#include "Board.h"
#include "AObjectShape.h"
#include <iostream>

#define R_GAME_DEBUG 0

namespace RSnakeGame
{
Board::Board()
{
#if R_GAME_DEBUG == 1
    std::cout <<"BoardObj created !" <<std::endl;
#endif
}

Board::~Board()
{
#if R_GAME_DEBUG == 1
    std::cout << "~Board()"<<std::endl;
    std::cout << "Number of Board walls to delete: "<<m_VecOfBoardWalls.size()<<std::endl;
#endif
    for(auto &pWallElement : m_VecOfBoardWalls)
    {
        delete pWallElement;
        pWallElement = nullptr;
    }
    m_VecOfBoardWalls.clear();
#if R_GAME_DEBUG == 1
    std::cout << "BoardObj deleted !" <<std::endl;
#endif
}

bool Board::AddBoardWall(AObjectShape *pWall)
{
    if(pWall == nullptr)
    {
        return false;
    }

    m_VecOfBoardWalls.push_back(pWall);
    return true;
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

}
