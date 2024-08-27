#include "Fruit.hpp"
#include "Collider.hpp"
#include "Constans.hpp"
#include "DrawableObject.hpp"
#include "ObjectFactory.hpp"
#include <cstdlib>
#include <ctime>

namespace RSnakeGame
{

bool Fruit::SEEDED_FOR_SRAND{false};

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
    int x = (rand() % (m_MaxGenPosX - 3 * Texture::DEFAULT_WIDTH)) + Texture::DEFAULT_WIDTH;
    int y = (rand() % (m_MaxGenPosY - 3 * Texture::DEFAULT_HEIGHT)) + Texture::DEFAULT_HEIGHT;
    return Point2D{x, y};
}

void Fruit::Draw() const
{
    m_pFruit->rotation += 0.1;
    m_pFruit->Draw();
}

bool Fruit::WasEaten(std::shared_ptr<DrawableObject> object)
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
    m_pFruit = ObjectFactory::Instance()->CreateFruit(coord, Texture::DEFAULT_WIDTH, Texture::DEFAULT_HEIGHT, 0.0, 1.0);
}
} // namespace RSnakeGame
