#include <memory>
#include "Engine.h"
#include "Snake.h"
#include "Board.h"
#include "Fruit.h"
#include "ScoreBoard.h"
#include "InputControl.h"
#include "IControl.h"

static const int WIDHT_GAMEBOARD_SIZE  {60};
static const int HEIGHT_GAMEBOARD_SIZE {15};

int main()
{
    RSnakeGame::Board gameBoard {HEIGHT_GAMEBOARD_SIZE, WIDHT_GAMEBOARD_SIZE};
    RSnakeGame::Snake snake {WIDHT_GAMEBOARD_SIZE / 2, HEIGHT_GAMEBOARD_SIZE / 2};
    RSnakeGame::Fruit fruit {WIDHT_GAMEBOARD_SIZE - 2, HEIGHT_GAMEBOARD_SIZE - 2};
    RSnakeGame::ScoreBoard scoreBoard {0, HEIGHT_GAMEBOARD_SIZE + 1};

    std::unique_ptr<RSnakeGame::IControl> pControl = std::make_unique<RSnakeGame::InputControl>();

    RSnakeGame::Engine GameEngineObj(gameBoard,
                                     snake,
                                     fruit,
                                     scoreBoard,
                                     std::move(pControl));
   GameEngineObj.GameLoop();
   return 0;
}
