#pragma once
#include "DrawableBlock.hpp"
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

    void AddPartOfSnakeBody(const int posX, const int posY);
    void Update();
    void Draw();
    bool IsCollision();
    int GetHeadSnakeX() const;
    int GetHeadSnakeY() const;
    void MoveSnake(SnakeDirection snakeDir);

  private:
    void CreateStartSnakeBodyShape(const int startPosX, const int startPosY);
    std::vector<std::shared_ptr<DrawableBlock>> m_SnakeBody;
    SnakeDirection m_SnakeDir;
    bool m_StartWaitFlag;
};
} // namespace RSnakeGame
