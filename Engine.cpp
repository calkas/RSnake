#include "Engine.h"
#include "AObjectShape.h"
#include "DBoardWall.h"
#include "DSnakeBody.h"
#include "DFruit.h"
#include "InputControl.h"
#include <windows.h>
#include <iostream>

#define R_GAME_DEBUG 0

namespace RSnakeGame
{
Engine::Engine()
{
    Init();
}

Engine::~Engine()
{
    delete m_pControl;
}

void Engine::GameLoop()
{
    std::cout<< "..::Start RSnake GameLoop()::.." <<std::endl;
    while (isGameRunning)
    {
        Input();
        HandleObjectCollision();
        if(!isGameRunning)
        {
            GameOverTitle();
            break;
        }
        Update();
        Draw();
        Sleep(GAME_SPEED);
    }
}

void Engine::Input()
{
    if(m_pControl->isUpPressed())
    {
        SnakeObj.MoveSnake(Snake::SnakeDirection::MOVE_SNAKE_UP);
    }
    else if(m_pControl->isDownPressed())
    {
        SnakeObj.MoveSnake(Snake::SnakeDirection::MOVE_SNAKE_DOWN);
    }
    else if(m_pControl->isLeftPressed())
    {
        SnakeObj.MoveSnake(Snake::SnakeDirection::MOVE_SNAKE_LEFT);

    }
    else if(m_pControl->isRightPressed())
    {
        SnakeObj.MoveSnake(Snake::SnakeDirection::MOVE_SNAKE_RIGHT);
    }
    else
    {
    }

}

void Engine::Update()
{
    FruitObj.Update();
    SnakeObj.Update();
}

void Engine::Draw()
{
    system("cls");
    GameBoardObj.Draw();
    SnakeObj.Draw();
    FruitObj.Draw();
}

void Engine::HandleObjectCollision()
{
    const bool isGameEndCollision = GameBoardObj.isCollision(SnakeObj.GetHeadSnakeX(), SnakeObj.GetHeadSnakeY()) || SnakeObj.isCollision();

    if(isGameEndCollision)
    {
        isGameRunning = false;
    }
    else if (FruitObj.isCollision(SnakeObj.GetHeadSnakeX(), SnakeObj.GetHeadSnakeY()))
    {
        SnakeObj.AddPartOfSnakeBody(SnakeObj.GetHeadSnakeX(), SnakeObj.GetHeadSnakeY());
    }
    else
    {

    }
}

void Engine::GameOverTitle()
{
    system("cls");
    std::cout << "GAME OVER" <<std::endl;
}

void Engine::Init()
{
    m_pControl = new InputControl();
    isGameRunning = true;
}

}
