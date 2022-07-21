#include "DBoardWall.h"
#include <iostream>
#include <cstdio>
#include <windows.h>

namespace RSnakeGame
{

DBoardWall::DBoardWall(int x, int y)
{
    m_posX = x;
    m_posY = y;
}

void DBoardWall::Draw()
{
    COORD coord { static_cast<short int>(m_posX), static_cast<short int>(m_posY) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    std::cout<<"#"<<std::flush;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}
}
