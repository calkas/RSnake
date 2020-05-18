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
        m_SnakeDir = Snake::SnakeDirection::MOVE_SNAKE_UP;
    }
    else if(m_pControl->isDownPressed())
    {
        m_SnakeDir = Snake::SnakeDirection::MOVE_SNAKE_DOWN;
    }
    else if(m_pControl->isLeftPressed())
    {
        m_SnakeDir = Snake::SnakeDirection::MOVE_SNAKE_LEFT;
    }
    else if(m_pControl->isRightPressed())
    {
        m_SnakeDir = Snake::SnakeDirection::MOVE_SNAKE_RIGHT;
    }
    else
    {
    }

}

void Engine::Update()
{
    SnakeObj.Update(m_SnakeDir);
    FruitObj.Update();
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
        //TODO
        SnakeObj.AddPartOfBody(CreateSnakeBodyShape(SnakeObj.GetHeadSnakeX(), SnakeObj.GetHeadSnakeY()));
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
    AddBodyShapeForBoard();
    AddBodyShapeForSnake();
    AddBodyShapeForFruit();
    isGameRunning = true;
}

void Engine::AddBodyShapeForBoard()
{
#if R_GAME_DEBUG == 1
    std::cout<<"Create GameBoard "<<WIDHT_GAMEBOARD_SIZE<<"x"<<HEIGHT_GAMEBOARD_SIZE<<std::endl;
#endif
    for(int lineId = 0; lineId < HEIGHT_GAMEBOARD_SIZE; lineId++)
    {
            if(lineId == 0 || lineId == (HEIGHT_GAMEBOARD_SIZE - 1))
            {
                for(int columnId = 0; columnId < WIDHT_GAMEBOARD_SIZE; columnId++)
                {
                    GameBoardObj.AddBoardWall(CreateWallShape(columnId,lineId));
                }
            }
            else
            {
                 GameBoardObj.AddBoardWall(CreateWallShape(0,lineId));
                 GameBoardObj.AddBoardWall(CreateWallShape(WIDHT_GAMEBOARD_SIZE - 1 ,lineId));
            }
    }
}

void Engine::AddBodyShapeForSnake()
{
    int startPosX = static_cast<int>( WIDHT_GAMEBOARD_SIZE / 2);
    int startPosY = static_cast<int>( HEIGHT_GAMEBOARD_SIZE / 2);
    SnakeObj.AddPartOfBody(CreateSnakeBodyShape(startPosX, startPosY));
    SnakeObj.AddPartOfBody(CreateSnakeBodyShape(startPosX + 1, startPosY));
    SnakeObj.AddPartOfBody(CreateSnakeBodyShape(startPosX + 2, startPosY));
}

void Engine::AddBodyShapeForFruit()
{
    FruitObj.AddFruitShape(CreateFruitShape(1,1));
    FruitObj.Update();
}

AObjectShape *Engine::CreateWallShape(int x, int y)
{
    AObjectShape *pWallObj = new DBoardWall(x,y);
    return pWallObj;
}

AObjectShape *Engine::CreateSnakeBodyShape(int x, int y)
{
    AObjectShape *pSnakeBodyObj = new DSnakeBody(x,y);
    return pSnakeBodyObj;
}

AObjectShape *Engine::CreateFruitShape(int x, int y)
{
    AObjectShape *pFruitObj = new DFruit(x,y);
    return pFruitObj;
}
}
