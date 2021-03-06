#include "Snake.h"
#include "AObjectShape.h"
#include "DBodyBuilder.h"
#include <iostream>

namespace RSnakeGame
{

Snake::Snake(int startPosX, int startPosY) : m_SnakeDir(SnakeDirection::MOVE_UNKNOWN), m_StartWaitFlag(true)
{
    CreateStartSnakeBodyShape(startPosX, startPosY);
}

Snake::~Snake()
{
    for(auto &pBodyElement : m_VecOfSnakeBody)
    {
        delete pBodyElement;
        pBodyElement = nullptr;
    }

    m_VecOfSnakeBody.clear();
}

void Snake::AddPartOfSnakeBody(int posX, int posY)
{
    AObjectShape *pSnakeBodyObj = CreateSnakeBodyShape(posX, posY);
    m_VecOfSnakeBody.push_back(pSnakeBodyObj);
}

void Snake::Update()
{
    int nX = GetHeadSnakeX();
    int nY = GetHeadSnakeY();

    switch (m_SnakeDir)
    {
        case SnakeDirection::MOVE_SNAKE_UP:
            m_VecOfSnakeBody[0]->m_posY -= 1;
            m_StartWaitFlag = false;
            break;
        case SnakeDirection::MOVE_SNAKE_DOWN:
            m_VecOfSnakeBody[0]->m_posY += 1;
            m_StartWaitFlag = false;
            break;
        case SnakeDirection::MOVE_SNAKE_LEFT:
            m_VecOfSnakeBody[0]->m_posX -= 1;
            m_StartWaitFlag = false;
            break;
        case SnakeDirection::MOVE_SNAKE_RIGHT:
            m_VecOfSnakeBody[0]->m_posX += 1;
            m_StartWaitFlag = false;
            break;
        default:
            break;
    }

    if(m_StartWaitFlag)
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
    for(int i = 2; i<m_VecOfSnakeBody.size(); i++)
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

void Snake::MoveSnake(Snake::SnakeDirection snakeDir)
{
    m_SnakeDir = snakeDir;
}

void Snake::CreateStartSnakeBodyShape(int startPosX, int startPosY)
{
    AddPartOfSnakeBody(startPosX, startPosY);
    AddPartOfSnakeBody(startPosX + 1, startPosY);
    AddPartOfSnakeBody(startPosX + 2, startPosY);
}
}
