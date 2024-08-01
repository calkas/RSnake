#include "ScoreBoard.h"

// #include <windows.h>

// #include <cstdio>
#include <iostream>

namespace RSnakeGame
{

ScoreBoard::ScoreBoard(int posX, int posY) : m_Score(0), posX(posX), posY(posY)
{
    Show();
}

void ScoreBoard::Update()
{
    m_Score += 10;
}

void ScoreBoard::Show()
{
    // COORD coord {static_cast<short int>(posX), static_cast<short
    // int>(posY)};

    // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    // std::cout<<"SCORE: "<<m_Score<<std::flush;
    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN |
    // FOREGROUND_BLUE | FOREGROUND_RED);
}

void ScoreBoard::GameOver()
{
    // COORD coord {0, 0};
    // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    // std::cout<<"===================\n" <<std::flush;
    // std::cout<<"..:: GAME OVER ::..\n\n\n" <<std::flush;
    // std::cout<<"YOUR SCORE: "<<m_Score<<"\n"<<std::flush;
    // std::cout<<"===================\n" <<std::flush;
    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN |
    // FOREGROUND_BLUE | FOREGROUND_RED);
}

} // namespace RSnakeGame
