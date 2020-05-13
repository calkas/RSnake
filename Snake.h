#ifndef SNAKE_H
#define SNAKE_H
#include <vector>

namespace RSnakeGame
{
class AObjectShape;

class Snake
{
public:
    Snake();
    ~Snake();

    bool AddPartOfBody(AObjectShape *pBodyElement);
    void Update(int posX, int posY);
    void Draw();
    bool isCollision(int x, int y);

    int GetHeadSnakeX() const;
    int GetHeadSnakeY() const;

private:
    std::vector<AObjectShape *> m_VecOfSnakeBody;
};
}
#endif // SNAKE_H
