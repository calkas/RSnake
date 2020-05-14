#include "Fruit.h"
#include "AObjectShape.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define R_GAME_DEBUG 0

namespace RSnakeGame
{

bool Fruit::SEEDED_FOR_SRAND = false;

Fruit::Fruit(int maxGenPosX, int maxGenPosY) : m_MaxGenPosX(maxGenPosX), m_MaxGenPosY(maxGenPosY)
{
    if(!SEEDED_FOR_SRAND)
    {
        srand(time(NULL));
        SEEDED_FOR_SRAND = true;
    }


#if R_GAME_DEBUG == 1
    std::cout << "FruitObj created !" <<std::endl;
#endif
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

bool Fruit::AddFruitShape(AObjectShape *pFruitShape)
{
    if(pFruitShape == nullptr)
    {
        return false;
    }
    m_pFruitShape = pFruitShape;
    return true;
}

void Fruit::Update()
{
    if(m_pFruitShape == nullptr)
    {
        return;
    }
    m_pFruitShape->m_posX = rand() % m_MaxGenPosX + 1;
    m_pFruitShape->m_posY = rand() % m_MaxGenPosY + 1;
}

void Fruit::Draw()
{
    if(m_pFruitShape == nullptr)
    {
        return;
    }

    //std::cout<<"Fruit x: "<< m_pFruitShape->m_posX <<std::endl;
    //std::cout<<"Fruit y: "<< m_pFruitShape->m_posY <<std::endl;
    m_pFruitShape->Draw();
}

bool Fruit::isCollision(int x, int y)
{
    if((m_pFruitShape->m_posX == x) && (m_pFruitShape->m_posY == y))
    {
        return true;
    }
    return false;
}
}
