#pragma once

#include <memory>
namespace sf
{
class RenderWindow;
class Font;
} // namespace sf

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
    explicit Engine(sf::RenderWindow &rGameWindow, sf::Font &rFont, Board &rBoard, Snake &rSnake, Fruit &rFruit,
                    ScoreBoard &rScoreBoard, std::unique_ptr<IControl> pControl);
    ~Engine() = default;
    Engine() = delete;
    void GameLoop();

  private:
    void ProcessInput();
    void Update();
    void Render();

    void HandleObjectCollision();
    void GameOverUi();
    void UserBoardUi();

    sf::RenderWindow &m_rWindow;
    sf::Font &m_rFont;
    Board &m_rGameBoard;
    Snake &m_rSnake;
    Fruit &m_rFruit;
    ScoreBoard &m_rScoreBoard;
    std::unique_ptr<IControl> m_pControl;
    bool m_GameRunning;
};

} // namespace RSnakeGame
