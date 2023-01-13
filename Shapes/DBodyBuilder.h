#ifndef DBODYBUILDER_H
#define DBODYBUILDER_H
#include <memory>
#include "AObjectShape.h"
namespace RSnakeGame
{
template<typename BodyShape>
std::unique_ptr<AObjectShape> CreateBodyShape(const int x, const int y)
{
    return std::make_unique<BodyShape>(x, y);
}

}
#endif // DBODYBUILDER_H
