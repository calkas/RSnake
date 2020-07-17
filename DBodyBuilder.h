#ifndef DBODYBUILDER_H
#define DBODYBUILDER_H
#include "AObjectShape.h"
namespace RSnakeGame
{

AObjectShape *CreateBoardWallShape(int x, int y);
AObjectShape *CreateSnakeBodyShape(int x, int y);
AObjectShape *CreateFruitBodyShape(int x, int y);

}
#endif // DBODYBUILDER_H
