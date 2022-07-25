#include "DSnakeBody.h"
#include <iostream>
#include <cstdio>
#include <windows.h>

namespace RSnakeGame
{

DSnakeBody::DSnakeBody(int x, int y) : AObjectShape(x,y)
{
}

void DSnakeBody::Draw()
{
    COORD coord { static_cast<short int>(m_posX), static_cast<short int>(m_posY) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    std::cout<<"o"<<std::flush;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}
}
