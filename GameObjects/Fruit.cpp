#include "Fruit.hpp"
#include "BlockFactory.hpp"
#include "DFruit.hpp"
#include "DrawableBlock.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

namespace RSnakeGame
{

const int FRUIT_BODY_HEIGHT = 10;
const int FRUIT_BODY_WIDTH = 10;
bool Fruit::SEEDED_FOR_SRAND = false;

Fruit::Fruit(int maxGenPosX, int maxGenPosY)
    : m_MaxGenPosX(maxGenPosX), m_MaxGenPosY(maxGenPosY), m_SnakeAteFruitFlag(false)
{
    CreateFruit(1, 1);
    if (!SEEDED_FOR_SRAND)
    {
        srand(static_cast<unsigned int>(time(NULL)));
        SEEDED_FOR_SRAND = true;
    }
    Update();
}

Fruit::~Fruit()
{
}

void Fruit::Update()
{
    static bool firstTime = true;
    if (m_pFruit == nullptr)
    {
        return;
    }

    if (m_SnakeAteFruitFlag || firstTime)
    {
        m_pFruit->posX = rand() % m_MaxGenPosX + 1;
        m_pFruit->posY = rand() % m_MaxGenPosY + 1;
        m_SnakeAteFruitFlag = false;
        firstTime = false;
    }
}

void Fruit::Draw() const
{
    if (m_pFruit == nullptr)
    {
        return;
    }
    m_pFruit->Draw();
}

bool Fruit::WasEaten(const int x, const int y)
{
    if ((m_pFruit->posX == x) && (m_pFruit->posY == y))
    {
        m_SnakeAteFruitFlag = true;
        return true;
    }
    return false;
}

void Fruit::CreateFruit(const int x, const int y)
{
    m_pFruit = std::move(BlockFactory::Instance()->CreateBlock(BlockFactory::BlockType::FRUIT, x, y, FRUIT_BODY_WIDTH,
                                                               FRUIT_BODY_HEIGHT));
}
} // namespace RSnakeGame
