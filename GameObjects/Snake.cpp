#include "Snake.hpp"
#include "BlockFactory.hpp"
#include "Collider.hpp"
#include "DSnakeBody.hpp"
#include "DrawableBlock.hpp"
#include <iostream>

namespace RSnakeGame
{

static const int SNAKE_BLOCK_BODY_WIDTH = BlockFactory::Instance()->SIMPLE_BLOCK_WIDTH;
static const int SNAKE_BLOCK_BODY_HEIGHT = BlockFactory::Instance()->SIMPLE_BLOCK_HEIGHT;

Snake::Snake(int startPosX, int startPosY) : m_SnakeDir(SnakeDirection::MOVE_SNAKE_LEFT), m_onHoldFlag(true)
{
    CreateHead(Point2D{startPosX, startPosY});
    AddBodyElement();
    AddBodyElement();
}

Snake::~Snake()
{
}

void Snake::AddBodyElement()
{
    auto point = ConvertDirectionToVector(m_SnakeDir);
    point.multiply(SNAKE_BLOCK_BODY_WIDTH, SNAKE_BLOCK_BODY_HEIGHT);
    auto lastElementIterator = m_SnakeBody.end() - 1;
    Point2D last = (*lastElementIterator)->position;
    last = last + point;

    m_SnakeBody.push_back(BlockFactory::Instance()->CreateBlock(BlockFactory::BlockType::SNAKE_BODY, last,
                                                                SNAKE_BLOCK_BODY_WIDTH, SNAKE_BLOCK_BODY_HEIGHT));
}

void Snake::Update()
{
    if (m_onHoldFlag)
        return;

    auto newPoint = GetHeadCoordinates();
    auto point = ConvertDirectionToVector(m_SnakeDir);
    point.multiply(SNAKE_BLOCK_BODY_WIDTH, SNAKE_BLOCK_BODY_HEIGHT);
    m_SnakeBody[0]->position = m_SnakeBody[0]->position + point;

    for (auto snakeTail = m_SnakeBody.begin() + 1; snakeTail != m_SnakeBody.end(); snakeTail++)
    {
        Point2D last = (*snakeTail)->position;
        (*snakeTail)->position = newPoint;
        newPoint = last;
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
    if (m_onHoldFlag)
        return false;

    for (auto bodyElementIt = m_SnakeBody.begin() + 1; bodyElementIt != m_SnakeBody.end(); bodyElementIt++)
    {
        if (m_SnakeBody[0]->position.x == (*bodyElementIt)->position.x &&
            m_SnakeBody[0]->position.y == (*bodyElementIt)->position.y)
        {
            return true;
        }
    }
    return false;
}

std::shared_ptr<DrawableBlock> Snake::GetHead() const
{
    return m_SnakeBody[0];
}

Point2D Snake::GetHeadCoordinates() const
{
    return m_SnakeBody[0]->position;
}

void Snake::MoveSnake(SnakeDirection snakeDir)
{
    if (m_SnakeDir != snakeDir)
    {
        m_onHoldFlag = false;
    }
    m_SnakeDir = snakeDir;
}

void Snake::CreateHead(Point2D coord)
{
    m_SnakeBody.push_back(BlockFactory::Instance()->CreateBlock(BlockFactory::BlockType::SNAKE_BODY, coord,
                                                                SNAKE_BLOCK_BODY_WIDTH, SNAKE_BLOCK_BODY_HEIGHT));
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
