#ifndef ENGINE_H
#define ENGINE_H

namespace RSnakeGame
{
class AObjectShape;
class Board;
class Snake;
class Fruit;
class IControl;
class ScoreBoard;

class Engine
{
public:
    Engine(Board *pBoard, Snake *pSnake, Fruit *pFruit, ScoreBoard *pScoreBoard, IControl *pControl);
    void GameLoop();

private:
    static const int GAME_SPEED = 300;

    void Input();
    void Update();
    void Draw();

    void HandleObjectCollision();
    void GameOverTitle();

    bool m_IsGameRunning;
    Board *m_pGameBoardObj;
    Snake *m_pSnakeObj;
    Fruit *m_pFruitObj;
    ScoreBoard *m_pScoreBoard;
    IControl *m_pControl;
};

}


#endif // ENGINE_H
