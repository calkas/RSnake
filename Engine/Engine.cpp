#include "Engine.hpp"
#include "Board.hpp"
#include "Constans.hpp"
#include "Controllable.hpp"
#include "Fruit.hpp"
#include "ResourceManager.hpp"
#include "ScoreBoard.hpp"
#include "Snake.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <string_view>

namespace RSnakeGame
{

namespace UiHelper
{
void RenderText(sf::RenderWindow &rGameWindow, std::string &&text, Point2D position,
                unsigned int size = Font::DEFAULT_SIZE)
{
    sf::Color UiColor{UI_RGB.r, UI_RGB.g, UI_RGB.b};
    sf::Text uiText;
    uiText.setString(text);
    uiText.setCharacterSize(size);
    uiText.setFillColor(UiColor);
    uiText.setPosition(position.x_f(), position.y_f());
    auto font = ResourceManager::Instance()->GetFont(RSnakeGame::Font::GLOBAL);
    if (font.has_value())
        uiText.setFont(*font.value());
    rGameWindow.draw(uiText);
}

void RenderUi(sf::RenderWindow &rGameWindow, const std::string_view textureName, Point2D position)
{
    sf::Sprite sprite;
    sprite.setPosition(position.x_f(), position.y_f());
    auto texture = ResourceManager::Instance()->GetTexture(textureName);
    if (texture.has_value())
        sprite.setTexture(*texture.value());
    rGameWindow.draw(sprite);
}
} // namespace UiHelper

Engine::Engine(sf::RenderWindow &rGameWindow, Board &rBoard, Snake &rSnake, Fruit &rFruit, ScoreBoard &rScoreBoard,
               std::unique_ptr<Controllable> pControl)
    : rGameWindow(rGameWindow), rGameBoard(rBoard), rSnake(rSnake), rFruit(rFruit), rScoreBoard(rScoreBoard),
      pController(std::move(pControl))
{
}

void Engine::Run()
{
    float speed = 0.15;
    sf::Clock gameClock;
    float previousTime = gameClock.getElapsedTime().asSeconds();
    float lag = 0.0;

    while (rGameWindow.isOpen())
    {
        if (isGameRunning)
        {
            float currentTime = gameClock.getElapsedTime().asSeconds();
            float elapsedTime = currentTime - previousTime;
            previousTime = currentTime;
            lag += elapsedTime;

            sf::Event event;
            while (rGameWindow.pollEvent(event))
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    isPaused = false;
                    ProcessInput();
                }
                if (event.type == sf::Event::Closed)
                {
                    rGameWindow.close();
                }
            }

            while (lag >= speed)
            {
                if (!isPaused)
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
            GameOver();
        }
    }
}
void Engine::ProcessInput()
{
    if (pController->isUpPressed())
        rSnake.Move(Direction::UP);
    else if (pController->isDownPressed())
        rSnake.Move(Direction::DOWN);
    else if (pController->isLeftPressed())
        rSnake.Move(Direction::LEFT);
    else if (pController->isRightPressed())
        rSnake.Move(Direction::RIGHT);
}

void Engine::Update()
{
    rSnake.Update();
    rFruit.Update();
}

void Engine::Render()
{
    rGameWindow.clear();

    UiHelper::RenderUi(rGameWindow, Texture::UI_FRAME, Point2D{Resolution::BOARD_WIDTH + 30, 0});
    UiHelper::RenderText(rGameWindow, "Score: " + std::to_string(rScoreBoard.GetScore()),
                         Point2D{Resolution::BOARD_WIDTH + 100, 285});

    rGameBoard.Draw();
    rSnake.Draw();
    rFruit.Draw();

    rGameWindow.display();
}

void Engine::HandleObjectCollision()
{
    if (rGameBoard.IsCollision(rSnake.GetHead()) || rSnake.IsCollision())
    {
        isGameRunning = false;
        return;
    }

    if (rFruit.WasEaten(rSnake.GetHead()))
    {
        rSnake.AddBodyElement();
        rScoreBoard.IncrementScore();
    }
}

void Engine::GameOver()
{
    sf::Event event;
    while (rGameWindow.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Key::Escape)
                ResetGame();
        }

        if (event.type == sf::Event::Closed)
            rGameWindow.close();
    }
    rGameWindow.clear();

    UiHelper::RenderUi(rGameWindow, Texture::UI_GAME_OVER,
                       Point2D{(Resolution::BOARD_WIDTH / 2), Resolution::BOARD_HEIGHT / 2 - 200});

    UiHelper::RenderText(rGameWindow, "Score: " + std::to_string(rScoreBoard.GetScore()),
                         Point2D{(Resolution::BOARD_WIDTH / 2 + 120), Resolution::BOARD_HEIGHT / 2 - 10});

    rGameWindow.display();
}

void Engine::ResetGame()
{
    isPaused = true;
    isGameRunning = true;
    rSnake.Reset();
    rScoreBoard.Reset();
}

} // namespace RSnakeGame
