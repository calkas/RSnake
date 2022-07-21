#ifndef DFRUIT_H
#define DFRUIT_H
#include "AObjectShape.h"

namespace RSnakeGame
{
class DFruit : public AObjectShape
{
public:
    DFruit(int x, int y);
    virtual void Draw() override;
};

}

#endif // DFRUIT_H
