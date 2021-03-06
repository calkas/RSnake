#include "DBodyBuilder.h"
#include "DBoardWall.h"
#include "DSnakeBody.h"
#include "DFruit.h"

namespace RSnakeGame
{

AObjectShape *CreateBoardWallShape(int x, int y)
{
    AObjectShape *pWallObj = new DBoardWall(x,y);
    return pWallObj;
}

AObjectShape *CreateSnakeBodyShape(int x, int y)
{
    AObjectShape *pSnakeBodyObj = new DSnakeBody(x, y);
    return pSnakeBodyObj;
}

AObjectShape *CreateFruitBodyShape(int x, int y)
{
    AObjectShape *pFruitBodyObj = new DFruit(x, y);
    return pFruitBodyObj;
}

}
