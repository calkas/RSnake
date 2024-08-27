#pragma once
#include "Constans.hpp"
#include "DrawableObject.hpp"
#include "Point2d.hpp"
#include <memory>
#include <vector>

namespace RSnakeGame
{

class Snake
{
  public:
    explicit Snake(int startPosX, int startPosY);
    ~Snake() = default;

    void AddBodyElement();
    void Update();
    void Draw();
    bool IsCollision();
    std::shared_ptr<DrawableObject> GetHead() const;
    void Move(Direction snakeDir);
    void Reset();

  private:
    std::shared_ptr<DrawableObject> GetTail() const;
    bool IsForbiddenMove(Direction newDir);
    void Create(Point2D point);
    Point2D GetHeadCoordinates() const;
    Point2D ConvertDirectionToVector(Direction snakeDir);
    Point2D startingPoint;
    std::vector<std::shared_ptr<DrawableObject>> m_SnakeBody{};
    Direction m_SnakeDir{Direction::LEFT};
    bool m_onHoldFlag{true};
};
} // namespace RSnakeGame
