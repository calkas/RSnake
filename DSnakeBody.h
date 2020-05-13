#ifndef DSNAKEBODY_H
#define DSNAKEBODY_H
#include "AObjectShape.h"

namespace RSnakeGame
{

class DSnakeBody : public AObjectShape
{
public:
    DSnakeBody(int x, int y);
    virtual void Draw() override;
};
}
#endif // DSNAKEBODY_H
