#include "Snake.h"
#include "AObjectShape.h"
#include <iostream>

#define R_GAME_DEBUG 0

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

void Snake::Update(SnakeDirection snakeDir)
{
    static bool startFlag = true;
    int nX = GetHeadSnakeX();
    int nY = GetHeadSnakeY();

    switch (snakeDir)
    {
        case MOVE_SNAKE_UP:
            m_VecOfSnakeBody[0]->m_posY -= 1;
            startFlag = false;
            break;
        case MOVE_SNAKE_DOWN:
            m_VecOfSnakeBody[0]->m_posY += 1;
            startFlag = false;
            break;
        case MOVE_SNAKE_LEFT:
            m_VecOfSnakeBody[0]->m_posX -= 1;
            startFlag = false;
            break;
        case MOVE_SNAKE_RIGHT:
            m_VecOfSnakeBody[0]->m_posX += 1;
            startFlag = false;
            break;
        default:
            break;
    }

    if(startFlag)
    {
        return;
    }

    int last_x, last_y;

    for(int i = 1; i <m_VecOfSnakeBody.size(); i++)
    {
        last_x = m_VecOfSnakeBody[i]->m_posX;
        last_y = m_VecOfSnakeBody[i]->m_posY;

        m_VecOfSnakeBody[i]->m_posX = nX;
        m_VecOfSnakeBody[i]->m_posY = nY;

        nX = last_x;
        nY = last_y;
    }

}

void Snake::Draw()
{
    for(const auto &pBodyElement : m_VecOfSnakeBody)
    {
        pBodyElement->Draw();
    }
}

bool Snake::isCollision()
{
    for(int i = 1; i<m_VecOfSnakeBody.size(); i++)
    {
        if((m_VecOfSnakeBody[i]->m_posX == m_VecOfSnakeBody[0]->m_posX) && (m_VecOfSnakeBody[i]->m_posY == m_VecOfSnakeBody[0]->m_posY))
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
