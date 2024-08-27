#include "Snake.hpp"
#include "Collider.hpp"
#include "ObjectFactory.hpp"
#include <iostream>
namespace RSnakeGame
{
Snake::Snake(int startPosX, int startPosY)
{
    Create(Point2D{startPosX, startPosY});
}

Snake::~Snake()
{
}

void Snake::AddBodyElement()
{
    auto point = ConvertDirectionToVector(m_SnakeDir);
    point.multiply(Texture::DEFAULT_WIDTH, Texture::DEFAULT_HEIGHT);
    auto lastElementIterator = m_SnakeBody.end() - 1;
    // Remove tail
    m_SnakeBody.pop_back();
    Point2D last = (*lastElementIterator)->position;

    // Add body element + new tail element
    m_SnakeBody.push_back(ObjectFactory::Instance()->CreateSnakeBody(SnakeBlockType::BODY, last, Texture::DEFAULT_WIDTH,
                                                                     Texture::DEFAULT_HEIGHT, 0, 1.0, 1.0));

    last = last + point;

    m_SnakeBody.push_back(ObjectFactory::Instance()->CreateSnakeBody(SnakeBlockType::TAIL, last, Texture::DEFAULT_WIDTH,
                                                                     Texture::DEFAULT_HEIGHT, 0, 1.0, 1.0));
}

float CalculateRotation(Point2D point)
{
    if (point.x == 0 && point.y == -1) // UP
    {
        return 90.0;
    }
    else if (point.x == 0 && point.y == 1) // DOWN
    {
        return 270.0;
    }
    else if (point.x == 1 && point.y == 0) // RIGHT
    {
        return 180.0;
    }
    else
    {
        return 0.0; // DEFAULT LEFT
    }
}

void Snake::Update()
{
    auto newPoint = GetHeadCoordinates();
    auto point = ConvertDirectionToVector(m_SnakeDir);

    GetHead()->rotation = CalculateRotation(point);

    point.multiply(Texture::DEFAULT_WIDTH, Texture::DEFAULT_HEIGHT);
    m_SnakeBody[0]->position = m_SnakeBody[0]->position + point;

    Point2D beforeTailA = (*(m_SnakeBody.end() - 2))->position;

    for (auto snakeTail = m_SnakeBody.begin() + 1; snakeTail != m_SnakeBody.end(); snakeTail++)
    {
        Point2D last = (*snakeTail)->position;
        (*snakeTail)->position = newPoint;
        newPoint = last;
    }

    Point2D beforeTailB = (*(m_SnakeBody.end() - 2))->position;

    Point2D diff = beforeTailB - beforeTailA;

    diff.x = diff.x / Texture::DEFAULT_WIDTH;
    diff.y = diff.y / Texture::DEFAULT_HEIGHT;

    GetTail()->rotation = CalculateRotation(diff);
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

std::shared_ptr<DrawableObject> Snake::GetHead() const
{
    return m_SnakeBody[0];
}

std::shared_ptr<DrawableObject> Snake::GetTail() const
{
    return (*(m_SnakeBody.end() - 1));
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

void Snake::Create(Point2D point)
{
    m_SnakeBody.push_back(ObjectFactory::Instance()->CreateSnakeBody(
        SnakeBlockType::HEAD, point, Texture::DEFAULT_WIDTH, Texture::DEFAULT_HEIGHT, 0, 1.0, 1.0));

    point.x = point.x + Texture::DEFAULT_WIDTH;

    m_SnakeBody.push_back(ObjectFactory::Instance()->CreateSnakeBody(
        SnakeBlockType::BODY, point, Texture::DEFAULT_WIDTH, Texture::DEFAULT_HEIGHT, 0, 1.0, 1.0));

    point.x = point.x + Texture::DEFAULT_WIDTH;

    m_SnakeBody.push_back(ObjectFactory::Instance()->CreateSnakeBody(
        SnakeBlockType::TAIL, point, Texture::DEFAULT_WIDTH, Texture::DEFAULT_HEIGHT, 0, 1.0, 1.0));
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
