#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <memory>

namespace RSnakeGame
{
class AObjectShape;

class Snake
{
public:
    enum class SnakeDirection{
        MOVE_SNAKE_UP,
        MOVE_SNAKE_DOWN,
        MOVE_SNAKE_LEFT,
        MOVE_SNAKE_RIGHT,
        MOVE_UNKNOWN,
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
    std::vector<std::shared_ptr<AObjectShape>>m_SnakeBody;
    SnakeDirection m_SnakeDir;
    bool m_StartWaitFlag;
};
}
#endif // SNAKE_H
