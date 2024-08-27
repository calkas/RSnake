#pragma once

#include <memory>
namespace sf
{
class RenderWindow;
class Font;
} // namespace sf

namespace RSnakeGame
{
class DrawableObject;
class Board;
class Snake;
class Fruit;
class IControl;
class ScoreBoard;
class ResourceManager;

class Engine
{
  public:
    explicit Engine(sf::RenderWindow &rGameWindow, Board &rBoard, Snake &rSnake, Fruit &rFruit, ScoreBoard &rScoreBoard,
                    std::unique_ptr<IControl> pControl);
    ~Engine() = default;
    void Run();

  private:
    void ProcessInput();
    void Update();
    void Render();

    void HandleObjectCollision();
    void GameOverUi();
    void UserBoardUi();

    sf::RenderWindow &m_rWindow;
    Board &m_rGameBoard;
    Snake &m_rSnake;
    Fruit &m_rFruit;
    ScoreBoard &m_rScoreBoard;
    std::unique_ptr<IControl> m_pControl;
    bool m_GameRunning{true};
    bool m_PauseFlag{true};
};

} // namespace RSnakeGame
