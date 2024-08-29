#pragma once
#include <memory>

namespace sf
{
class RenderWindow;
} // namespace sf

namespace RSnakeGame
{
class DrawableObject;
class Board;
class Snake;
class Fruit;
class Controllable;
class ScoreBoard;
class ResourceManager;

class Engine
{
  public:
    explicit Engine(sf::RenderWindow &rGameWindow, Board &rBoard, Snake &rSnake, Fruit &rFruit, ScoreBoard &rScoreBoard,
                    std::unique_ptr<Controllable> pControl);
    ~Engine() = default;
    void Run();

  private:
    void ProcessInput();
    void Update();
    void Render();
    void ResetGame();
    void HandleObjectCollision();
    void GameOver();

    sf::RenderWindow &rGameWindow;
    Board &rGameBoard;
    Snake &rSnake;
    Fruit &rFruit;
    ScoreBoard &rScoreBoard;
    std::unique_ptr<Controllable> pController;
    bool isGameRunning{true};
    bool isPaused{true};
};

} // namespace RSnakeGame
