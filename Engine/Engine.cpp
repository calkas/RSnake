#include "Engine.hpp"
#include "Board.hpp"
#include "Fruit.hpp"
#include "IControl.hpp"
#include "ScoreBoard.hpp"
#include "Snake.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

namespace RSnakeGame
{

Engine::Engine(sf::RenderWindow &rGameWindow, sf::Font &rFont, Board &rBoard, Snake &rSnake, Fruit &rFruit,
               ScoreBoard &rScoreBoard, std::unique_ptr<IControl> pControl)
    : m_rWindow(rGameWindow), m_rFont(rFont), m_rGameBoard(rBoard), m_rSnake(rSnake), m_rFruit(rFruit),
      m_rScoreBoard(rScoreBoard), m_pControl(std::move(pControl))
{
}

void Engine::GameLoop()
{
    sf::Clock gameClock;
    float previousTime = gameClock.getElapsedTime().asSeconds();
    float lag = 0.0;

    while (m_rWindow.isOpen() && m_GameRunning)
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
                m_PauseFlag = false;
                ProcessInput();
            }
            if (event.type == sf::Event::Closed)
            {
                m_rWindow.close();
            }
        }

        while (lag >= 0.1)
        {
            if (!m_PauseFlag)
            {
                HandleObjectCollision();
                Update();
            }
            lag -= 0.1;
        }
        Render();
    }

    if (!m_GameRunning)
    {
        GameOverUi();
    }
}

void Engine::ProcessInput()
{
    if (m_pControl->isUpPressed())
        m_rSnake.Move(Snake::Direction::UP);
    else if (m_pControl->isDownPressed())
        m_rSnake.Move(Snake::Direction::DOWN);
    else if (m_pControl->isLeftPressed())
        m_rSnake.Move(Snake::Direction::LEFT);
    else if (m_pControl->isRightPressed())
        m_rSnake.Move(Snake::Direction::RIGHT);
}

void Engine::Update()
{
    m_rSnake.Update();
    m_rFruit.Update();
}

void Engine::Render()
{
    m_rWindow.clear();

    UserBoardUi();

    m_rGameBoard.Draw();
    m_rSnake.Draw();
    m_rFruit.Draw();

    m_rWindow.display();
}

void Engine::HandleObjectCollision()
{
    const bool isBoardCollision = m_rGameBoard.IsCollision(m_rSnake.GetHead());
    const bool isSnakeCollision = m_rSnake.IsCollision();

    if (isBoardCollision || isSnakeCollision)
    {
        m_GameRunning = false;
        return;
    }

    if (m_rFruit.WasEaten(m_rSnake.GetHead()))
    {
        m_rSnake.AddBodyElement();
        m_rScoreBoard.IncrementScore();
    }
}

void Engine::UserBoardUi()
{
    sf::Text titleText;
    titleText.setString("RSnake Game");
    titleText.setCharacterSize(24);
    titleText.setFillColor(sf::Color::Magenta);
    titleText.setFont(m_rFont);
    titleText.setPosition(m_rGameBoard.m_width + 10, 10);

    sf::Text scoreText;
    scoreText.setString("Score: " + std::to_string(m_rScoreBoard.GetScore()));
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setFont(m_rFont);
    scoreText.setPosition(m_rGameBoard.m_width + 10, m_rGameBoard.m_height - 50);

    m_rWindow.draw(titleText);
    m_rWindow.draw(scoreText);
}

void Engine::GameOverUi()
{

    sf::Text gameOverText;
    gameOverText.setString("   Game Over   \n Your Score: " + std::to_string(m_rScoreBoard.GetScore()));
    gameOverText.setCharacterSize(28);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition((m_rGameBoard.m_width / 2) - 100, m_rGameBoard.m_height / 2);
    gameOverText.setFont(m_rFont);

    while (m_rWindow.isOpen())
    {
        sf::Event event;
        while (m_rWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_rWindow.close();
            }
        }
        m_rWindow.clear();
        m_rGameBoard.Draw();
        m_rWindow.draw(gameOverText);
        m_rWindow.display();
    }
}
} // namespace RSnakeGame
