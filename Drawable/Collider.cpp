#include "Collider.hpp"

namespace RSnakeGame
{

namespace Collider
{

namespace Rectangle
{

bool isCollisionDetected(const DrawableObject &rect1, const DrawableObject &rect2)
{
    if (rect1.position.x < rect2.position.x + rect2.width && rect1.position.x + rect1.width > rect2.position.x &&
        rect1.position.y < rect2.position.y + rect2.height && rect1.position.y + rect1.height > rect2.position.y)
    {
        return true;
    }
    return false;
}

} // namespace Rectangle

} // namespace Collider

} // namespace RSnakeGame
