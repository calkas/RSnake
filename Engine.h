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

    Snake SnakeObj {WIDHT_GAMEBOARD_SIZE / 2, HEIGHT_GAMEBOARD_SIZE / 2};
    Board GameBoardObj {HEIGHT_GAMEBOARD_SIZE, WIDHT_GAMEBOARD_SIZE};
    Fruit FruitObj {WIDHT_GAMEBOARD_SIZE - 2, HEIGHT_GAMEBOARD_SIZE - 2};

    IControl *m_pControl;
    bool isGameRunning;
};

}


#endif // ENGINE_H
