#include "Engine.hpp"

#include "Board.hpp"
#include "Fruit.hpp"
#include "IControl.hpp"
#include "ScoreBoard.h"
#include "Snake.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace RSnakeGame
{

Engine::Engine(sf::RenderWindow &rGameWindow, Board &rBoard, Snake &rSnake, Fruit &rFruit, ScoreBoard &rScoreBoard,
               std::unique_ptr<IControl> pControl)
    : m_rWindow(rGameWindow), m_rGameBoard(rBoard), m_rSnake(rSnake), m_rFruit(rFruit), m_rScoreBoard(rScoreBoard),
      m_pControl(std::move(pControl)), m_GameRunning(true)
{
}

void Engine::GameLoop()
{

    sf::Clock gameClock;
    float previousTime = gameClock.getElapsedTime().asSeconds();
    float lag = 0.0;

    while (m_rWindow.isOpen())
    {
        float currentTime = gameClock.getElapsedTime().asSeconds();
        float elapsedTime = currentTime - previousTime;
        previousTime = currentTime;
        lag += elapsedTime;

        sf::Event event;
        while (m_rWindow.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                ProcessInput();
            }
            if (event.type == sf::Event::Closed)
                m_rWindow.close();
        }

        HandleObjectCollision();

        while (lag >= 0.1)
        {
            Update();
            lag -= 0.1;
        }

        Render();
    }
}

void Engine::ProcessInput()
{
    if (m_pControl->isUpPressed())
        m_rSnake.MoveSnake(Snake::SnakeDirection::MOVE_SNAKE_UP);
    else if (m_pControl->isDownPressed())
        m_rSnake.MoveSnake(Snake::SnakeDirection::MOVE_SNAKE_DOWN);
    else if (m_pControl->isLeftPressed())
        m_rSnake.MoveSnake(Snake::SnakeDirection::MOVE_SNAKE_LEFT);
    else if (m_pControl->isRightPressed())
        m_rSnake.MoveSnake(Snake::SnakeDirection::MOVE_SNAKE_RIGHT);
}

void Engine::Update()
{
    m_rSnake.Update();
    m_rFruit.Update();
}

void Engine::Render()
{
    m_rWindow.clear();
    m_rGameBoard.Draw();
    m_rSnake.Draw();
    m_rFruit.Draw();
    m_rScoreBoard.Show();
    m_rWindow.display();
}

void Engine::HandleObjectCollision()
{
    const bool isGameEndCollision =
        m_rGameBoard.IsCollision(m_rSnake.GetHeadSnakeX(), m_rSnake.GetHeadSnakeY()) || m_rSnake.IsCollision();

    if (isGameEndCollision)
    {
        m_GameRunning = false;
        return;
    }

    if (m_rFruit.WasEaten(m_rSnake.GetHeadSnakeX(), m_rSnake.GetHeadSnakeY()))
    {
        m_rSnake.AddPartOfSnakeBody(m_rSnake.GetHeadSnakeX(), m_rSnake.GetHeadSnakeY());
        m_rScoreBoard.Update();
    }
}

void Engine::GameOver()
{
    m_rScoreBoard.GameOver();
}
} // namespace RSnakeGame
