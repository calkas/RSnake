#include "Snake.hpp"
#include "BlockFactory.hpp"
#include "DSnakeBody.hpp"
#include "DrawableBlock.hpp"
#include "Point2d.hpp"
#include <iostream>

namespace RSnakeGame
{

static const int SNAKE_BLOCK_BODY_SIZE = BlockFactory::Instance()->SIMPLE_BLOCK_SIZE;

static const int SNAKE_BLOCK_BODY_WIDTH = BlockFactory::Instance()->SIMPLE_BLOCK_SIZE;
static const int SNAKE_BLOCK_BODY_HEIGHT = BlockFactory::Instance()->SIMPLE_BLOCK_SIZE;

Snake::Snake(int startPosX, int startPosY) : m_SnakeDir(SnakeDirection::MOVE_SNAKE_LEFT), m_StartWaitFlag(true)
{
    CreateStartSnakeBodyShape(startPosX, startPosY);
}

Snake::~Snake()
{
}

void Snake::AddPartOfSnakeBody(const int posX, const int posY)
{
    m_SnakeBody.push_back(BlockFactory::Instance()->CreateBlock(BlockFactory::BlockType::SNAKE_BODY, posX, posY,
                                                                SNAKE_BLOCK_BODY_SIZE, SNAKE_BLOCK_BODY_SIZE));
}

void Snake::Update()
{
    int nX = GetHeadSnakeX();
    int nY = GetHeadSnakeY();

    switch (m_SnakeDir)
    {
    case SnakeDirection::MOVE_SNAKE_UP:
        m_SnakeBody[0]->posY -= 1 * SNAKE_BLOCK_BODY_HEIGHT;
        m_StartWaitFlag = false;
        break;
    case SnakeDirection::MOVE_SNAKE_DOWN:
        m_SnakeBody[0]->posY += 1 * SNAKE_BLOCK_BODY_HEIGHT;
        m_StartWaitFlag = false;
        break;
    case SnakeDirection::MOVE_SNAKE_LEFT:
        m_SnakeBody[0]->posX -= 1 * SNAKE_BLOCK_BODY_WIDTH;
        m_StartWaitFlag = false;
        break;
    case SnakeDirection::MOVE_SNAKE_RIGHT:
        m_SnakeBody[0]->posX += 1 * SNAKE_BLOCK_BODY_WIDTH;
        m_StartWaitFlag = false;
        break;
    }

    if (m_StartWaitFlag)
    {
        return;
    }

    int last_x, last_y;
    for (auto bodyElementIt = m_SnakeBody.begin() + 1; bodyElementIt != m_SnakeBody.end(); bodyElementIt++)
    {
        last_x = (*bodyElementIt)->posX;
        last_y = (*bodyElementIt)->posY;

        (*bodyElementIt)->posX = nX;
        (*bodyElementIt)->posY = nY;

        nX = last_x;
        nY = last_y;
    }
}

void Snake::Draw()
{
    for (const auto &pBodyElement : m_SnakeBody)
    {
        pBodyElement->Draw();
    }
}

bool Snake::IsCollision()
{
    for (auto bodyElementIt = m_SnakeBody.begin() + 2; bodyElementIt != m_SnakeBody.end(); bodyElementIt++)
    {
        if (((*bodyElementIt)->posX == GetHeadSnakeX()) && ((*bodyElementIt)->posY == GetHeadSnakeY()))
        {
            return true;
        }
    }
    return false;
}

int Snake::GetHeadSnakeX() const
{
    return m_SnakeBody[0]->posX;
}

int Snake::GetHeadSnakeY() const
{
    return m_SnakeBody[0]->posY;
}

void Snake::MoveSnake(Snake::SnakeDirection snakeDir)
{
    m_SnakeDir = snakeDir;
}

void Snake::CreateStartSnakeBodyShape(const int startPosX, const int startPosY)
{
    AddPartOfSnakeBody(startPosX, startPosY);
    AddPartOfSnakeBody(startPosX + 1 * SNAKE_BLOCK_BODY_WIDTH, startPosY);
    AddPartOfSnakeBody(startPosX + 2 * SNAKE_BLOCK_BODY_WIDTH, startPosY);
}
} // namespace RSnakeGame
