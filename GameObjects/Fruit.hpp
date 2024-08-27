#pragma once
#include "DrawableObject.hpp"
#include "Point2d.hpp"
#include <memory>

namespace RSnakeGame
{

class Fruit
{
  public:
    explicit Fruit(int maxGenPosX, int maxGenPosY);
    ~Fruit() = default;

    void Update();
    void Draw() const;
    bool WasEaten(std::shared_ptr<DrawableObject> object);

  private:
    Point2D GenerateCoordinates() const;
    void CreateFruit(Point2D coord);
    std::shared_ptr<DrawableObject> m_pFruit;
    int m_MaxGenPosX;
    int m_MaxGenPosY;
    bool m_SnakeAteFruitFlag;
    static bool SEEDED_FOR_SRAND;
};
} // namespace RSnakeGame
