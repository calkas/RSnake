#include <iostream>
#include "Engine.h"
#include "Snake.h"
#include "Board.h"
#include "Fruit.h"
#include "InputControl.h"
#include "IControl.h"

using namespace std;

static const int WIDHT_GAMEBOARD_SIZE  = 40;
static const int HEIGHT_GAMEBOARD_SIZE = 15;

int main()
{
    RSnakeGame::Board GameBoardObj {HEIGHT_GAMEBOARD_SIZE, WIDHT_GAMEBOARD_SIZE};
    RSnakeGame::Snake SnakeObj {WIDHT_GAMEBOARD_SIZE / 2, HEIGHT_GAMEBOARD_SIZE / 2};
    RSnakeGame::Fruit FruitObj {WIDHT_GAMEBOARD_SIZE - 2, HEIGHT_GAMEBOARD_SIZE - 2};
    RSnakeGame::IControl *pControl = new RSnakeGame::InputControl();

    RSnakeGame::Engine GameEngineObj(&GameBoardObj, &SnakeObj, &FruitObj, pControl);
    GameEngineObj.GameLoop();

    delete pControl;

    cout<<"\n\n\n"<<endl;

    return 0;
}
