
#include "BlockFactory.hpp"
#include "Board.hpp"
#include "Constans.hpp"
#include "Engine.hpp"
#include "Fruit.hpp"
#include "IControl.hpp"
#include "InputControl.hpp"
#include "ResourceManager.hpp"
#include "ScoreBoard.hpp"
#include "Snake.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

static void LoadResources()
{
    // Load Fonts
    std::filesystem::path fontPath = std::string(RSnakeGame::Font::PATH) + std::string("Roboto-Bold.ttf");
    RSnakeGame::ResourceManager::Instance()->LoadFont(fontPath, RSnakeGame::Font::GLOBAL);

    // Load Textures
}

int main()
{
    std::cout << "Welcome to Snake Game" << std::endl;
    sf::RenderWindow gameWindow(sf::VideoMode(RSnakeGame::Resolution::WIDTH + 200, RSnakeGame::Resolution::HEIGHT),
                                RSnakeGame::TITLE);

    LoadResources();

    RSnakeGame::BlockFactory::Instance()->SetRenderer(&gameWindow);
    RSnakeGame::Board gameBoard{RSnakeGame::Resolution::HEIGHT, RSnakeGame::Resolution::WIDTH};
    RSnakeGame::Snake snake{RSnakeGame::Resolution::WIDTH / 2, RSnakeGame::Resolution::HEIGHT / 2};
    RSnakeGame::Fruit fruit{RSnakeGame::Resolution::WIDTH - 2, RSnakeGame::Resolution::HEIGHT - 2};
    RSnakeGame::ScoreBoard scoreBoard;

    std::unique_ptr<RSnakeGame::IControl> pControl = std::make_unique<RSnakeGame::InputControl>();

    RSnakeGame::Engine game(gameWindow, gameBoard, snake, fruit, scoreBoard, std::move(pControl));
    game.GameLoop();

    return 0;
}
