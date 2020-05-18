#ifndef SNAKE_H
#define SNAKE_H
#include <vector>

namespace RSnakeGame
{
class AObjectShape;

class Snake
{
public:
    enum SnakeDirection{
        MOVE_SNAKE_UP,
        MOVE_SNAKE_DOWN,
        MOVE_SNAKE_LEFT,
        MOVE_SNAKE_RIGHT
    };
    Snake();
    ~Snake();

    bool AddPartOfBody(AObjectShape *pBodyElement);
    void Update(SnakeDirection snakeDir);
    void Draw();
    bool isCollision();

    int GetHeadSnakeX() const;
    int GetHeadSnakeY() const;

private:
    std::vector<AObjectShape *> m_VecOfSnakeBody;
};
}
#endif // SNAKE_H
