
#include "Board.hpp"
#include "Constans.hpp"
#include "Engine.hpp"
#include "Fruit.hpp"
#include "IControl.hpp"
#include "InputControl.hpp"
#include "ObjectFactory.hpp"
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
    std::filesystem::path texturePath = std::string(RSnakeGame::Texture::PATH);

    for (const auto &entry : std::filesystem::directory_iterator(texturePath))
    {
        std::string fullname = entry.path().filename();
        size_t lastindex = fullname.find_last_of(".");
        std::string textureName = fullname.substr(0, lastindex);
        RSnakeGame::ResourceManager::Instance()->LoadTexture(entry.path(), textureName);
    }
}

int main()
{
    std::cout << "Welcome to Snake Game" << std::endl;
    sf::RenderWindow renderWindow{sf::VideoMode(1024, 728), RSnakeGame::TITLE};

    LoadResources();

    RSnakeGame::ObjectFactory::Instance()->SetRenderer(&renderWindow);
    RSnakeGame::Board gameBoard{RSnakeGame::Resolution::HEIGHT, RSnakeGame::Resolution::WIDTH};
    RSnakeGame::Snake snake{RSnakeGame::Resolution::WIDTH / 2, RSnakeGame::Resolution::HEIGHT / 2};
    RSnakeGame::Fruit fruit{RSnakeGame::Resolution::WIDTH - 2, RSnakeGame::Resolution::HEIGHT - 2};
    RSnakeGame::ScoreBoard scoreBoard;

    std::unique_ptr<RSnakeGame::IControl> pControl = std::make_unique<RSnakeGame::InputControl>();

    RSnakeGame::Engine game(renderWindow, gameBoard, snake, fruit, scoreBoard, std::move(pControl));
    game.GameLoop();

    return 0;
}
