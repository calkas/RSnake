#include "Fruit.hpp"
#include "BlockFactory.hpp"
#include "Collider.hpp"
#include "DFruit.hpp"
#include "DrawableBlock.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

namespace RSnakeGame
{

const int FRUIT_BODY_HEIGHT = BlockFactory::SIMPLE_BLOCK_HEIGHT;
const int FRUIT_BODY_WIDTH = BlockFactory::SIMPLE_BLOCK_WIDTH;
bool Fruit::SEEDED_FOR_SRAND = false;

Fruit::Fruit(int screenWidth, int screenHeight)
    : m_MaxGenPosX(screenWidth), m_MaxGenPosY(screenHeight), m_SnakeAteFruitFlag(false)
{
    if (!SEEDED_FOR_SRAND)
    {
        srand(static_cast<unsigned int>(time(NULL)));
        SEEDED_FOR_SRAND = true;
    }
    CreateFruit(GenerateCoordinates());
}

Fruit::~Fruit()
{
}

void Fruit::Update()
{
    if (m_SnakeAteFruitFlag)
    {
        m_pFruit->position = GenerateCoordinates();
        m_SnakeAteFruitFlag = false;
    }
}

Point2D Fruit::GenerateCoordinates() const
{
    int x = (rand() % (m_MaxGenPosX - 3 * FRUIT_BODY_WIDTH)) + FRUIT_BODY_WIDTH;
    int y = (rand() % (m_MaxGenPosY - 3 * FRUIT_BODY_HEIGHT)) + FRUIT_BODY_HEIGHT;
    return Point2D{x, y};
}

void Fruit::Draw() const
{
    m_pFruit->Draw();
}

bool Fruit::WasEaten(std::shared_ptr<DrawableBlock> object)
{
    if (Collider::Rectangle::isCollisionDetected(*m_pFruit, *object))
    {
        m_SnakeAteFruitFlag = true;
        return true;
    }
    return false;
}

void Fruit::CreateFruit(Point2D coord)
{
    m_pFruit = std::move(BlockFactory::Instance()->CreateBlock(BlockFactory::BlockType::FRUIT, coord, FRUIT_BODY_WIDTH,
                                                               FRUIT_BODY_HEIGHT));
}
} // namespace RSnakeGame
