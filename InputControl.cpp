#include "InputControl.h"
#include <windows.h>
namespace RSnakeGame
{
bool InputControl::isUpPressed()
{
    return isKeyPressed(VK_UP);
}

bool InputControl::isDownPressed()
{
    return isKeyPressed(VK_DOWN);
}

bool InputControl::isLeftPressed()
{
    return isKeyPressed(VK_LEFT);
}

bool InputControl::isRightPressed()
{
    return isKeyPressed(VK_RIGHT);
}

bool InputControl::isKeyPressed(int key)
{
    return (GetAsyncKeyState(key) & 0x8000 != 0);
}
}
