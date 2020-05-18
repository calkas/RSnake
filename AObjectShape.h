#ifndef AOBJECTSHAPE_HPP
#define AOBJECTSHAPE_HPP

namespace RSnakeGame
{
struct AObjectShape
{
    virtual ~AObjectShape() {}
    virtual void Draw() = 0;
    int m_posX;
    int m_posY;
};
}
#endif // AOBJECTSHAPE_HPP
