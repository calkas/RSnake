#ifndef ENGINE_H
#define ENGINE_H

namespace RSnakeGame
{
class AObjectShape;
class Board;
class Snake;
class Fruit;
class IControl;

class Engine
{
public:
    Engine(Board *pBoard, Snake *pSnake, Fruit *pFruit, IControl *pControl);
    void GameLoop();

private:
    static const int GAME_SPEED = 300;

    void Input();
    void Update();
    void Draw();

    void HandleObjectCollision();
    void GameOverTitle();

    bool isGameRunning;
    Board *m_pGameBoardObj;
    Snake *m_pSnakeObj;
    Fruit *m_pFruitObj;
    IControl *m_pControl;
};

}


#endif // ENGINE_H
