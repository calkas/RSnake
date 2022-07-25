#ifndef DBODYBUILDER_H
#define DBODYBUILDER_H
#include <memory>
#include "AObjectShape.h"
namespace RSnakeGame
{

std::unique_ptr<AObjectShape> CreateBoardWallShape(const int x, const int y);
std::unique_ptr<AObjectShape> CreateSnakeBodyShape(const int x, const int y);
std::unique_ptr<AObjectShape> CreateFruitBodyShape(const int x, const int y);

}
#endif // DBODYBUILDER_H
