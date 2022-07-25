#include "DBodyBuilder.h"
#include "DBoardWall.h"
#include "DSnakeBody.h"
#include "DFruit.h"

namespace RSnakeGame
{

std::unique_ptr<AObjectShape> CreateBoardWallShape(const int x, const int y)
{
    return std::make_unique<DBoardWall>(x,y);
}

std::unique_ptr<AObjectShape> CreateSnakeBodyShape(const int x, const int y)
{
    return std::make_unique<DSnakeBody>(x,y);
}

std::unique_ptr<AObjectShape> CreateFruitBodyShape(const int x, const int y)
{
    return std::make_unique<DFruit>(x,y);
}

}
