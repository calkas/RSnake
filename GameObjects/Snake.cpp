#include "Snake.hpp"
#include "BlockFactory.hpp"
#include "DSnakeBody.hpp"
#include "DrawableBlock.hpp"
#include <iostream>

namespace RSnakeGame
{

static const int SNAKE_BLOCK_BODY_WIDTH = BlockFactory::Instance()->SIMPLE_BLOCK_SIZE;
static const int SNAKE_BLOCK_BODY_HEIGHT = BlockFactory::Instance()->SIMPLE_BLOCK_SIZE;

Snake::Snake(int startPosX, int startPosY) : m_SnakeDir(SnakeDirection::MOVE_SNAKE_LEFT), m_StartWaitFlag(true)
{
    CreateHead(startPosX, startPosY);
    AddBodyElement();
    AddBodyElement();
}

Snake::~Snake()
{
}

void Snake::AddBodyElement()
{
    auto point = ConvertDirectionToVector(m_SnakeDir);
    point.x *= SNAKE_BLOCK_BODY_WIDTH;
    point.y *= SNAKE_BLOCK_BODY_HEIGHT;

    auto lastElement = m_SnakeBody.back();

    m_SnakeBody.push_back(BlockFactory::Instance()->CreateBlock(
        BlockFactory::BlockType::SNAKE_BODY, lastElement->posX + point.x, lastElement->posY + point.y,
        SNAKE_BLOCK_BODY_WIDTH, SNAKE_BLOCK_BODY_HEIGHT));
}

void Snake::Update()
{
    auto newPoint = GetHeadCoordinates();

    auto point = ConvertDirectionToVector(m_SnakeDir);
    m_SnakeBody[0]->posX += point.x * SNAKE_BLOCK_BODY_WIDTH;
    m_SnakeBody[0]->posY += point.y * SNAKE_BLOCK_BODY_HEIGHT;

    int last_x, last_y;
    for (auto snakeTail = m_SnakeBody.begin() + 1; snakeTail != m_SnakeBody.end(); snakeTail++)
    {
        last_x = (*snakeTail)->posX;
        last_y = (*snakeTail)->posY;

        (*snakeTail)->posX = newPoint.x;
        (*snakeTail)->posY = newPoint.y;

        newPoint.x = last_x;
        newPoint.y = last_y;
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
    // for (auto bodyElementIt = m_SnakeBody.begin() + 2; bodyElementIt != m_SnakeBody.end(); bodyElementIt++)
    // {
    //     if (((*bodyElementIt)->posX == GetHeadSnakeX()) && ((*bodyElementIt)->posY == GetHeadSnakeY()))
    //     {
    //         return true;
    //     }
    // }
    // return false;
}

Point2D Snake::GetHeadCoordinates() const
{
    return {m_SnakeBody[0]->posX, m_SnakeBody[0]->posY};
}

void Snake::MoveSnake(Snake::SnakeDirection snakeDir)
{
    m_SnakeDir = snakeDir;
}

void Snake::CreateHead(const int startPosX, const int startPosY)
{
    m_SnakeBody.push_back(BlockFactory::Instance()->CreateBlock(
        BlockFactory::BlockType::SNAKE_BODY, startPosX, startPosY, SNAKE_BLOCK_BODY_WIDTH, SNAKE_BLOCK_BODY_HEIGHT));
}

Point2D Snake::ConvertDirectionToVector(SnakeDirection snakeDir)
{
    switch (snakeDir)
    {
    case Snake::SnakeDirection::MOVE_SNAKE_UP:
        return {0, -1};
    case Snake::SnakeDirection::MOVE_SNAKE_DOWN:
        return {0, 1};
    case Snake::SnakeDirection::MOVE_SNAKE_LEFT:
        return {-1, 0};
    case Snake::SnakeDirection::MOVE_SNAKE_RIGHT:
        return {1, 0};
    }
}
} // namespace RSnakeGame
