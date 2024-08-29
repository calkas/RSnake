
#include "Board.hpp"
#include "Constans.hpp"
#include "Controllable.hpp"
#include "Engine.hpp"
#include "Fruit.hpp"
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
        size_t lastIndex = fullname.find_last_of(".");
        std::string textureName = fullname.substr(0, lastIndex);
        if (RSnakeGame::DEBUG_MODE)
            std::cout << " * Loading texture: " << textureName << std::endl;
        RSnakeGame::ResourceManager::Instance()->LoadTexture(entry.path(), textureName);
    }
}

int main()
{
    std::cout << "..:: Welcome to Snake Game ::.." << std::endl;
    sf::RenderWindow renderWindow{
        sf::VideoMode(RSnakeGame::Resolution::BOARD_WIDTH + 400, RSnakeGame::Resolution::BOARD_HEIGHT),
        RSnakeGame::TITLE};

    LoadResources();

    RSnakeGame::ObjectFactory::Instance()->SetRenderer(&renderWindow);
    RSnakeGame::Board gameBoard;
    RSnakeGame::Snake snake{RSnakeGame::Resolution::BOARD_WIDTH / 2, RSnakeGame::Resolution::BOARD_HEIGHT / 2};
    RSnakeGame::Fruit fruit{RSnakeGame::Resolution::BOARD_WIDTH - 2, RSnakeGame::Resolution::BOARD_HEIGHT - 2};
    RSnakeGame::ScoreBoard scoreBoard;

    std::unique_ptr<RSnakeGame::Controllable> pControl = std::make_unique<RSnakeGame::InputControl>();

    RSnakeGame::Engine game(renderWindow, gameBoard, snake, fruit, scoreBoard, std::move(pControl));
    game.Run();

    return 0;
}
