#include "Engine.h"
#include "Board.h"
#include "Snake.h"
#include "Fruit.h"
#include "IControl.h"
#include <windows.h>
#include <iostream>

namespace RSnakeGame
{

Engine::Engine(Board *pBoard, Snake *pSnake, Fruit *pFruit, IControl *pControl) :
    m_pGameBoardObj(pBoard), m_pSnakeObj(pSnake), m_pFruitObj(pFruit), m_pControl(pControl)
{
    isGameRunning = true;
}

void Engine::GameLoop()
{
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
        m_pSnakeObj->MoveSnake(Snake::SnakeDirection::MOVE_SNAKE_UP);
    }
    else if(m_pControl->isDownPressed())
    {
        m_pSnakeObj->MoveSnake(Snake::SnakeDirection::MOVE_SNAKE_DOWN);
    }
    else if(m_pControl->isLeftPressed())
    {
        m_pSnakeObj->MoveSnake(Snake::SnakeDirection::MOVE_SNAKE_LEFT);

    }
    else if(m_pControl->isRightPressed())
    {
        m_pSnakeObj->MoveSnake(Snake::SnakeDirection::MOVE_SNAKE_RIGHT);
    }
    else
    {
        //Do Nothing
    }

}

void Engine::Update()
{
    m_pFruitObj->Update();
    m_pSnakeObj->Update();
}

void Engine::Draw()
{
    system("cls");
    m_pGameBoardObj->Draw();
    m_pSnakeObj->Draw();
    m_pFruitObj->Draw();
}

void Engine::HandleObjectCollision()
{
    const bool isGameEndCollision = m_pGameBoardObj->isCollision(m_pSnakeObj->GetHeadSnakeX(), m_pSnakeObj->GetHeadSnakeY()) ||
            m_pSnakeObj->isCollision();

    if(isGameEndCollision)
    {
        isGameRunning = false;
    }
    else if (m_pFruitObj->isCollision(m_pSnakeObj->GetHeadSnakeX(), m_pSnakeObj->GetHeadSnakeY()))
    {
        m_pSnakeObj->AddPartOfSnakeBody(m_pSnakeObj->GetHeadSnakeX(), m_pSnakeObj->GetHeadSnakeY());
    }
    else
    {

    }
}

void Engine::GameOverTitle()
{
    system("cls");
    std::cout<< "..:: GAME OVER ::.." <<std::endl;
}
}
