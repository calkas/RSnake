#ifndef AOBJECTSHAPE_HPP
#define AOBJECTSHAPE_HPP

namespace RSnakeGame
{
struct AObjectShape
{
    AObjectShape(int x, int y) : m_posX(x), m_posY(y) {}
    virtual ~AObjectShape() = default;
    virtual void Draw() = 0;
    int m_posX;
    int m_posY;
};
}
#endif // AOBJECTSHAPE_HPP
