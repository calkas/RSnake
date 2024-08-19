#include "Snake.hpp"
#include "BlockFactory.hpp"
#include "Collider.hpp"
#include "DSnakeBody.hpp"

namespace RSnakeGame
{

static const int SNAKE_BLOCK_BODY_WIDTH = BlockFactory::Instance()->SIMPLE_BLOCK_WIDTH;
static const int SNAKE_BLOCK_BODY_HEIGHT = BlockFactory::Instance()->SIMPLE_BLOCK_HEIGHT;

Snake::Snake(int startPosX, int startPosY)
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

void Snake::Move(Direction snakeDir)
{
    if (IsForbiddenMove(snakeDir))
        return;
    m_SnakeDir = snakeDir;
}

bool Snake::IsForbiddenMove(Direction newDir)
{
    switch (m_SnakeDir)
    {
    case Direction::UP:
        return newDir == Direction::DOWN;
    case Direction::DOWN:
        return newDir == Direction::UP;
    case Direction::LEFT:
        return newDir == Direction::RIGHT;
    case Direction::RIGHT:
        return newDir == Direction::LEFT;
    }
}

void Snake::CreateHead(Point2D coord)
{
    m_SnakeBody.push_back(BlockFactory::Instance()->CreateBlock(BlockFactory::BlockType::SNAKE_BODY, coord,
                                                                SNAKE_BLOCK_BODY_WIDTH, SNAKE_BLOCK_BODY_HEIGHT));
}

Point2D Snake::ConvertDirectionToVector(Direction snakeDir)
{
    switch (snakeDir)
    {
    case Direction::UP:
        return {0, -1};
    case Direction::DOWN:
        return {0, 1};
    case Direction::LEFT:
        return {-1, 0};
    case Direction::RIGHT:
        return {1, 0};
    }
}
} // namespace RSnakeGame
