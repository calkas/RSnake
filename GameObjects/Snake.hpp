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
    enum class SnakeDirection
    {
        MOVE_SNAKE_UP,
        MOVE_SNAKE_DOWN,
        MOVE_SNAKE_LEFT,
        MOVE_SNAKE_RIGHT,
    };
    Snake(int startPosX, int startPosY);
    ~Snake();

    void AddBodyElement();
    void Update();
    void Draw();
    bool IsCollision();
    Point2D GetHeadCoordinates() const;
    std::shared_ptr<DrawableBlock> GetHead() const;
    void MoveSnake(SnakeDirection snakeDir);

  private:
    void CreateHead(Point2D coord);
    Point2D ConvertDirectionToVector(SnakeDirection snakeDir);
    std::vector<std::shared_ptr<DrawableBlock>> m_SnakeBody;
    SnakeDirection m_SnakeDir;
    bool m_onHoldFlag;
};
} // namespace RSnakeGame
