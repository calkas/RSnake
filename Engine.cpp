#include "Engine.h"
#include "AObjectShape.h"
#include "DBoardWall.h"
#include "DSnakeBody.h"
#include "DFruit.h"
#include <windows.h>

#include <iostream>

#define R_GAME_DEBUG 0

namespace RSnakeGame
{
Engine::Engine()
{
    Init();
}

void Engine::GameLoop()
{
    std::cout<< "..::Start RSnake GameLoop()::.." <<std::endl;
    while (isGameRunning)
    {
        Input();
        //Update();
        Draw();
        Sleep(1000);
    }
}

void Engine::Input()
{
    SnakeObj.Update(SnakeObj.GetHeadSnakeX(),SnakeObj.GetHeadSnakeY() -1);


}

void Engine::Update(int x, int y)
{
    SnakeObj.Update(x,y);
    FruitObj.Update();
}

void Engine::Draw()
{
    system("cls");
    GameBoardObj.Draw();
    SnakeObj.Draw();
    FruitObj.Draw();
}

void Engine::Init()
{
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
#if R_GAME_DEBUG == 1
        //const int expNumberOfWallsToCreate = (X_GAMEBOARD_SIZE * Y_GAMEBOARD_SIZE) - ((X_GAMEBOARD_SIZE - 2) * (Y_GAMEBOARD_SIZE - 2));
        //std::cout << "Expected number of Board Objects: "<<expNumberOfWallsToCreate<<std::endl;
        std::cout << "Actual number of Board Objects: "<<GameBoardObj.GetNumberOfWalls()<<std::endl;
#endif
}

void Engine::AddBodyShapeForSnake()
{
    int startPosX =  static_cast<int>( WIDHT_GAMEBOARD_SIZE / 2);
    int startPosY =  static_cast<int>( HEIGHT_GAMEBOARD_SIZE / 2);

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
