#pragma once

#include <memory>
namespace sf
{
class RenderWindow;
}

namespace RSnakeGame
{
class DrawableBlock;
class Board;
class Snake;
class Fruit;
class IControl;
class ScoreBoard;

class Engine
{
  public:
    explicit Engine(sf::RenderWindow &rGameWindow, Board &rBoard, Snake &rSnake, Fruit &rFruit, ScoreBoard &rScoreBoard,
                    std::unique_ptr<IControl> pControl);
    ~Engine() = default;
    Engine() = delete;
    void GameLoop();

  private:
    void ProcessInput();
    void Update();
    void Render();

    void HandleObjectCollision();
    void GameOver();

    sf::RenderWindow &m_rWindow;
    Board &m_rGameBoard;
    Snake &m_rSnake;
    Fruit &m_rFruit;
    ScoreBoard &m_rScoreBoard;
    std::unique_ptr<IControl> m_pControl;
    bool m_GameRunning;
};

} // namespace RSnakeGame
