#ifndef DBOARDWALL_H
#define DBOARDWALL_H
#include "AObjectShape.h"

namespace RSnakeGame
{

class DBoardWall : public AObjectShape
{
public:
    DBoardWall(int x, int y);
    virtual void Draw() override;
};

}

#endif // DBOARDWALL_H
