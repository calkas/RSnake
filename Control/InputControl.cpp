#include "InputControl.h"
#include <windows.h>

namespace RSnakeGame
{

bool InputControl::isUpPressed() const
{
    return isKeyPressed(VK_UP);
}

bool InputControl::isDownPressed() const
{
    return isKeyPressed(VK_DOWN);
}

bool InputControl::isLeftPressed() const
{
    return isKeyPressed(VK_LEFT);
}

bool InputControl::isRightPressed() const
{
    return isKeyPressed(VK_RIGHT);
}

bool InputControl::isKeyPressed(const int key) const
{
    return (GetAsyncKeyState(key) & 0x8000 != 0);
}

}
