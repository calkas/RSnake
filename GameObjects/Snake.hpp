#pragma once
#include "DrawableBlock.hpp"
#include "Point2d.hpp"
#include <memory>
#include <vector>

namespace RSnakeGame
{

class Snake
{
  public:
    enum class Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
    };
    Snake(int startPosX, int startPosY);
    ~Snake();

    void AddBodyElement();
    void Update();
    void Draw();
    bool IsCollision();
    Point2D GetHeadCoordinates() const;
    std::shared_ptr<DrawableBlock> GetHead() const;
    void Move(Direction snakeDir);

  private:
    void CreateHead(Point2D coord);
    Point2D ConvertDirectionToVector(Direction snakeDir);
    std::vector<std::shared_ptr<DrawableBlock>> m_SnakeBody;
    Direction m_SnakeDir{Direction::LEFT};
    bool m_onHoldFlag{true};
};
} // namespace RSnakeGame
