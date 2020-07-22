#include "DSnakeBody.h"
#include <iostream>
#include <cstdio>
#include <windows.h>

namespace RSnakeGame
{

DSnakeBody::DSnakeBody(int x, int y)
{
    m_posX = x;
    m_posY = y;
}

void DSnakeBody::Draw()
{
    COORD coord;
    coord.X = m_posX;
    coord.Y = m_posY;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord);
    std::cout<<"*"<<std::flush;
}
}
