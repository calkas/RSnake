#ifndef ENGINE_H
#define ENGINE_H
#include "Snake.h"
#include "Board.h"
#include "Fruit.h"

namespace RSnakeGame
{

class AObjectShape;

class Engine
{
public:
    Engine();

    void GameLoop();


private:
    static const int WIDHT_GAMEBOARD_SIZE = 15;
    static const int HEIGHT_GAMEBOARD_SIZE = 15;


    void Init();
    void Input();
    void Update(int x, int y);
    void Draw();


    void AddBodyShapeForBoard();
    void AddBodyShapeForSnake();
    void AddBodyShapeForFruit();

    AObjectShape *CreateWallShape(int x, int y);
    AObjectShape *CreateSnakeBodyShape(int x, int y);
    AObjectShape *CreateFruitShape(int x, int y);

    Snake SnakeObj;
    Board GameBoardObj;
    Fruit FruitObj {WIDHT_GAMEBOARD_SIZE, HEIGHT_GAMEBOARD_SIZE};

    bool isGameRunning;
};

}


#endif // ENGINE_H
