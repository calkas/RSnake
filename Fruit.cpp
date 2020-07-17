#include "Fruit.h"
#include "AObjectShape.h"
#include "DFruit.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define R_GAME_DEBUG 0

namespace RSnakeGame
{

bool Fruit::SEEDED_FOR_SRAND = false;

Fruit::Fruit(int maxGenPosX, int maxGenPosY) : m_MaxGenPosX(maxGenPosX),
    m_MaxGenPosY(maxGenPosY), m_SnakeAteFruitFlag(false)
{

    CreateFruit(1,1);
    if(!SEEDED_FOR_SRAND)
    {
        srand(time(NULL));
        SEEDED_FOR_SRAND = true;
    }
#if R_GAME_DEBUG == 1
    std::cout << "FruitObj created !" <<std::endl;
#endif

    Update();
}

Fruit::~Fruit()
{
    delete m_pFruitShape;
    m_pFruitShape = nullptr;
#if R_GAME_DEBUG == 1
    std::cout << "~Fruit()" <<std::endl;
    std::cout << "FruitObj deleted !" <<std::endl;
#endif
}

void Fruit::Update()
{
    static bool firstTime =true;
    if(m_pFruitShape == nullptr)
    {
        return;
    }

    if(m_SnakeAteFruitFlag || firstTime)
    {
        m_pFruitShape->m_posX = rand() % m_MaxGenPosX + 1;
        m_pFruitShape->m_posY = rand() % m_MaxGenPosY + 1;
        m_SnakeAteFruitFlag = false;
        firstTime = false;
    }

}

void Fruit::Draw()
{
    if(m_pFruitShape == nullptr)
    {
        return;
    }
    m_pFruitShape->Draw();
}

bool Fruit::isCollision(int x, int y)
{
    if((m_pFruitShape->m_posX == x) && (m_pFruitShape->m_posY == y))
    {
        m_SnakeAteFruitFlag = true;
        return true;
    }
    return false;
}

void Fruit::CreateFruit(int x, int y)
{
    m_pFruitShape = new DFruit(x,y);

}
}
