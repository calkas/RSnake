#ifndef ENGINE_H
#define ENGINE_H
#include "Snake.h"
#include "Board.h"
#include "Fruit.h"
#include "IControl.h"

namespace RSnakeGame
{
class IControl;
class AObjectShape;

class Engine
{
public:
    Engine();
    ~Engine();
    void GameLoop();

private:
    static const int WIDHT_GAMEBOARD_SIZE = 40;
    static const int HEIGHT_GAMEBOARD_SIZE = 15;
    static const int GAME_SPEED = 300;


    void Init();
    void Input();
    void Update();
    void Draw();

    void HandleObjectCollision();
    void GameOverTitle();


    void AddBodyShapeForBoard();
    void AddBodyShapeForSnake();
    void AddBodyShapeForFruit();

    AObjectShape *CreateWallShape(int x, int y);
    AObjectShape *CreateSnakeBodyShape(int x, int y);
    AObjectShape *CreateFruitShape(int x, int y);

    Snake SnakeObj;
    Board GameBoardObj;
    Fruit FruitObj {WIDHT_GAMEBOARD_SIZE - 2, HEIGHT_GAMEBOARD_SIZE - 2};

    IControl *m_pControl;
    bool isGameRunning;

    Snake::SnakeDirection m_SnakeDir;
};

}


#endif // ENGINE_H
