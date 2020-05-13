#include "Snake.h"
#include "AObjectShape.h"
#include <iostream>

#define R_GAME_DEBUG 1

namespace RSnakeGame
{
Snake::Snake()
{
#if R_GAME_DEBUG == 1
    std::cout << "SnakeObj created !" <<std::endl;
#endif
}

Snake::~Snake()
{
#if R_GAME_DEBUG == 1
    std::cout << "~Snake()"<<std::endl;
    std::cout << "Number of part of bodies: "<<m_VecOfSnakeBody.size()<<std::endl;
#endif
    for(auto &pBodyElement : m_VecOfSnakeBody)
    {
        delete pBodyElement;
        pBodyElement = nullptr;
    }

    m_VecOfSnakeBody.clear();

#if R_GAME_DEBUG == 1
    std::cout << "SnakeObj deleted !" <<std::endl;
#endif
}

bool Snake::AddPartOfBody(AObjectShape *pBodyElement)
{
    if(pBodyElement == nullptr)
    {
        return false;
    }
    m_VecOfSnakeBody.push_back(pBodyElement);
    return true;
}

void Snake::Update(int posX, int posY)
{

}

void Snake::Draw()
{
    for(const auto &pBodyElement : m_VecOfSnakeBody)
    {
        pBodyElement->Draw();
    }
}

bool Snake::isCollision(int x, int y)
{
    for(const auto &pBodyElement : m_VecOfSnakeBody)
    {
        if((pBodyElement->m_posX == x) && (pBodyElement->m_posY == y))
        {
            return true;
        }
    }
    return false;
}

int Snake::GetHeadSnakeX() const
{
    return m_VecOfSnakeBody[0]->m_posX;
}

int Snake::GetHeadSnakeY() const
{
    return m_VecOfSnakeBody[0]->m_posY;
}
}
