#ifndef ENGINE_H
#define ENGINE_H

#include <memory>

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
    explicit Engine(Board &rBoard, Snake &rSnake, Fruit &rFruit, ScoreBoard &rScoreBoard, std::unique_ptr<IControl> pControl);
    ~Engine() = default;
    Engine() = delete;
    void GameLoop();

private:
    static const int GAME_SPEED = 300;

    void Input();
    void Update();
    void Draw();

    void HandleObjectCollision();
    void GameOver();

    bool m_GameRunning;
    Board &m_rGameBoard;
    Snake &m_rSnake;
    Fruit &m_rFruit;
    ScoreBoard &m_rScoreBoard;
    std::unique_ptr<IControl> m_pControl;
};

}


#endif // ENGINE_H
