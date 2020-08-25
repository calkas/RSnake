#ifndef SNAKE_H
#define SNAKE_H
#include <vector>

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

    void AddPartOfSnakeBody(int posX, int posY);
    void Update();
    void Draw();
    bool isCollision();
    int GetHeadSnakeX() const;
    int GetHeadSnakeY() const;
    void MoveSnake(SnakeDirection snakeDir);

private:
    void CreateStartSnakeBodyShape(int startPosX, int startPosY);
    std::vector<AObjectShape *> m_VecOfSnakeBody;
    SnakeDirection m_SnakeDir;
    bool m_StartWaitFlag;
};
}
#endif // SNAKE_H
