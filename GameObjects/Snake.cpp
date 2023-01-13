#include "Snake.h"
#include "AObjectShape.h"
#include "DBodyBuilder.h"
#include "DSnakeBody.h"

namespace RSnakeGame
{

Snake::Snake(int startPosX, int startPosY) :
    m_SnakeDir(SnakeDirection::MOVE_UNKNOWN),
    m_StartWaitFlag(true)
{
    CreateStartSnakeBodyShape(startPosX, startPosY);
}

Snake::~Snake()
{
}

void Snake::AddPartOfSnakeBody(const int posX, const int posY)
{
    m_SnakeBody.push_back(CreateBodyShape<DSnakeBody>(posX, posY));
}

void Snake::Update()
{
    int nX = GetHeadSnakeX();
    int nY = GetHeadSnakeY();

    switch (m_SnakeDir)
    {
        case SnakeDirection::MOVE_SNAKE_UP:
            m_SnakeBody[0]->m_posY -= 1;
            m_StartWaitFlag = false;
            break;
        case SnakeDirection::MOVE_SNAKE_DOWN:
            m_SnakeBody[0]->m_posY += 1;
            m_StartWaitFlag = false;
            break;
        case SnakeDirection::MOVE_SNAKE_LEFT:
            m_SnakeBody[0]->m_posX -= 1;
            m_StartWaitFlag = false;
            break;
        case SnakeDirection::MOVE_SNAKE_RIGHT:
            m_SnakeBody[0]->m_posX += 1;
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

    for(auto bodyElementIt = m_SnakeBody.begin() + 1; bodyElementIt != m_SnakeBody.end(); bodyElementIt++)
    {
        last_x = (*bodyElementIt)->m_posX;
        last_y = (*bodyElementIt)->m_posY;

        (*bodyElementIt)->m_posX = nX;
        (*bodyElementIt)->m_posY = nY;

        nX = last_x;
        nY = last_y;
    }
}

void Snake::Draw()
{
    for(const auto &pBodyElement : m_SnakeBody)
    {
        pBodyElement->Draw();
    }
}

bool Snake::IsCollision()
{
    for(auto bodyElementIt = m_SnakeBody.begin() + 2; bodyElementIt != m_SnakeBody.end(); bodyElementIt++)
    {
        if(((*bodyElementIt)->m_posX == GetHeadSnakeX()) && ((*bodyElementIt)->m_posY == GetHeadSnakeY()))
        {
            return true;
        }
    }
    return false;
}

int Snake::GetHeadSnakeX() const
{
    return m_SnakeBody[0]->m_posX;
}

int Snake::GetHeadSnakeY() const
{
    return m_SnakeBody[0]->m_posY;
}

void Snake::MoveSnake(Snake::SnakeDirection snakeDir)
{
    m_SnakeDir = snakeDir;
}

void Snake::CreateStartSnakeBodyShape(const int startPosX, const int startPosY)
{
    AddPartOfSnakeBody(startPosX, startPosY);
    AddPartOfSnakeBody(startPosX + 1, startPosY);
    AddPartOfSnakeBody(startPosX + 2, startPosY);
}
}
