#ifndef DBOARDWALL_H
#define DBOARDWALL_H
#include "AObjectShape.h"

namespace RSnakeGame
{
struct DBoardWall : AObjectShape
{
    DBoardWall(int x, int y);
    virtual void Draw() override;
};

}

#endif // DBOARDWALL_H
