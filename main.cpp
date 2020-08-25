#include <iostream>
#include "Engine/Engine.h"
#include "GameObjects/Snake.h"
#include "GameObjects/Board.h"
#include "GameObjects/Fruit.h"
#include "GameObjects/ScoreBoard.h"
#include "Control/InputControl.h"
#include "Control/IControl.h"

using namespace std;

static const int WIDHT_GAMEBOARD_SIZE  {40};
static const int HEIGHT_GAMEBOARD_SIZE {15};

int main()
{
    RSnakeGame::Board GameBoardObj {HEIGHT_GAMEBOARD_SIZE, WIDHT_GAMEBOARD_SIZE};
    RSnakeGame::Snake SnakeObj {WIDHT_GAMEBOARD_SIZE / 2, HEIGHT_GAMEBOARD_SIZE / 2};
    RSnakeGame::Fruit FruitObj {WIDHT_GAMEBOARD_SIZE - 2, HEIGHT_GAMEBOARD_SIZE - 2};
    RSnakeGame::ScoreBoard ScoreBoardObj {0, HEIGHT_GAMEBOARD_SIZE + 1};
    RSnakeGame::IControl *pControl = new RSnakeGame::InputControl();

    RSnakeGame::Engine GameEngineObj(&GameBoardObj,
                                     &SnakeObj,
                                     &FruitObj,
                                     &ScoreBoardObj,
                                     pControl);
    GameEngineObj.GameLoop();

    delete pControl;
    return 0;
}
