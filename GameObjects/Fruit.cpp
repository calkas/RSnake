#include "Fruit.h"
#include "AObjectShape.h"
#include "DBodyBuilder.h"
#include "DFruit.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace RSnakeGame
{

bool Fruit::SEEDED_FOR_SRAND = false;

Fruit::Fruit(int maxGenPosX, int maxGenPosY) : m_MaxGenPosX(maxGenPosX),
    m_MaxGenPosY(maxGenPosY), m_SnakeAteFruitFlag(false)
{
    CreateFruit(1,1);
    if(!SEEDED_FOR_SRAND)
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
    static bool firstTime =true;
    if(m_pFruit == nullptr)
    {
        return;
    }

    if(m_SnakeAteFruitFlag || firstTime)
    {
        m_pFruit->m_posX = rand() % m_MaxGenPosX + 1;
        m_pFruit->m_posY = rand() % m_MaxGenPosY + 1;
        m_SnakeAteFruitFlag = false;
        firstTime = false;
    }
}

void Fruit::Draw() const
{
    if(m_pFruit == nullptr)
    {
        return;
    }
    m_pFruit->Draw();
}

bool Fruit::WasEaten(const int x, const int y)
{
    if((m_pFruit->m_posX == x) && (m_pFruit->m_posY == y))
    {
        m_SnakeAteFruitFlag = true;
        return true;
    }
    return false;
}

void Fruit::CreateFruit(const int x, const int y)
{
    m_pFruit = std::move(CreateBodyShape<DFruit>(x,y));
}
}
