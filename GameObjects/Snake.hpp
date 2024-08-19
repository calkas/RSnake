#pragma once
#include "Constans.hpp"
#include "DrawableBlock.hpp"
#include "Point2d.hpp"
#include <memory>
#include <vector>

namespace RSnakeGame
{

class Snake
{
  public:
    Snake(int startPosX, int startPosY);
    ~Snake();

    void AddBodyElement();
    void Update();
    void Draw();
    bool IsCollision();
    std::shared_ptr<DrawableBlock> GetHead() const;
    void Move(Direction snakeDir);

  private:
    bool IsForbiddenMove(Direction newDir);
    void Create(Point2D point);
    Point2D GetHeadCoordinates() const;
    Point2D ConvertDirectionToVector(Direction snakeDir);
    std::vector<std::shared_ptr<DrawableBlock>> m_SnakeBody{};
    Direction m_SnakeDir{Direction::LEFT};
    bool m_onHoldFlag{true};
};
} // namespace RSnakeGame
