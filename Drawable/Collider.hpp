#pragma once
#include "DrawableObject.hpp"

namespace RSnakeGame
{

namespace Collider
{

namespace Rectangle
{

bool isCollisionDetected(const DrawableObject &rect1, const DrawableObject &rect2);

} // namespace Rectangle

} // namespace Collider

} // namespace RSnakeGame
