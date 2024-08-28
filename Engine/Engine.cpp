#include "Engine.hpp"
#include "Board.hpp"
#include "Constans.hpp"
#include "Fruit.hpp"
#include "IControl.hpp"
#include "ResourceManager.hpp"
#include "ScoreBoard.hpp"
#include "Snake.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

namespace RSnakeGame
{

Engine::Engine(sf::RenderWindow &rGameWindow, Board &rBoard, Snake &rSnake, Fruit &rFruit, ScoreBoard &rScoreBoard,
               std::unique_ptr<IControl> pControl)
    : m_rWindow(rGameWindow), m_rGameBoard(rBoard), m_rSnake(rSnake), m_rFruit(rFruit), m_rScoreBoard(rScoreBoard),
      m_pControl(std::move(pControl))
{
}

void Engine::Run()
{
    float speed = 0.15;
    sf::Clock gameClock;
    float previousTime = gameClock.getElapsedTime().asSeconds();
    float lag = 0.0;

    while (m_rWindow.isOpen())
    {
        if (m_GameRunning)
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

            while (lag >= speed)
            {
                if (!m_PauseFlag)
                {
                    HandleObjectCollision();
                    Update();
                }
                lag -= speed;
            }
            Render();
        }
        else
        {
            GameOverUi();
        }
    }
}
void Engine::ProcessInput()
{
    if (m_pControl->isUpPressed())
        m_rSnake.Move(Direction::UP);
    else if (m_pControl->isDownPressed())
        m_rSnake.Move(Direction::DOWN);
    else if (m_pControl->isLeftPressed())
        m_rSnake.Move(Direction::LEFT);
    else if (m_pControl->isRightPressed())
        m_rSnake.Move(Direction::RIGHT);
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
    auto font = ResourceManager::Instance()->GetFont(RSnakeGame::Font::GLOBAL);
    sf::Text scoreText;
    if (font.has_value())
        scoreText.setFont(*font.value());

    auto texture = ResourceManager::Instance()->GetTexture(RSnakeGame::Texture::UI_FRAME);
    if (texture.has_value())
    {
        sf::Sprite sprite;
        sprite.setTexture(*texture.value());
        sprite.setPosition(Resolution::BOARD_WIDTH + 30, 0);
        m_rWindow.draw(sprite);
    }

    scoreText.setString("Score: " + std::to_string(m_rScoreBoard.GetScore()));
    scoreText.setCharacterSize(Font::DEFAULT_SIZE);
    sf::Color uiColor{UI_COLOR.r, UI_COLOR.g, UI_COLOR.b};
    scoreText.setFillColor(uiColor);
    scoreText.setPosition(Resolution::BOARD_WIDTH + 100, 285);
    m_rWindow.draw(scoreText);
}

void Engine::GameOverUi()
{
    sf::Color uiColor{UI_COLOR.r, UI_COLOR.g, UI_COLOR.b};
    sf::Sprite spriteGameOver;
    spriteGameOver.setPosition((Resolution::BOARD_WIDTH / 2), Resolution::BOARD_HEIGHT / 2 - 200);
    auto texture = ResourceManager::Instance()->GetTexture(RSnakeGame::Texture::UI_GAME_OVER);
    if (texture.has_value())
        spriteGameOver.setTexture(*texture.value());

    sf::Text gameOverText;
    gameOverText.setString("Score: " + std::to_string(m_rScoreBoard.GetScore()));
    gameOverText.setCharacterSize(Font::DEFAULT_SIZE);
    gameOverText.setFillColor(uiColor);
    gameOverText.setPosition((Resolution::BOARD_WIDTH / 2 + 120), Resolution::BOARD_HEIGHT / 2 - 10);
    auto font = ResourceManager::Instance()->GetFont(RSnakeGame::Font::GLOBAL);
    if (font.has_value())
        gameOverText.setFont(*font.value());

    sf::Event event;
    while (m_rWindow.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Key::Escape)
            {
                m_PauseFlag = true;
                m_GameRunning = true;
                m_rSnake.Reset();
                m_rScoreBoard.Reset();
            }
        }

        if (event.type == sf::Event::Closed)
        {
            m_rWindow.close();
        }
    }
    m_rWindow.clear();
    m_rWindow.draw(spriteGameOver);
    m_rWindow.draw(gameOverText);
    m_rWindow.display();
}
} // namespace RSnakeGame
