
#include "BlockFactory.hpp"
#include "Board.hpp"
#include "Engine.hpp"
#include "Fruit.hpp"
#include "IControl.hpp"
#include "InputControl.hpp"
#include "ScoreBoard.hpp"
#include "Snake.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

static const int WIDHT_GAMEBOARD_SIZE{600};
static const int HEIGHT_GAMEBOARD_SIZE{400};

int main()
{
    sf::Font font;
    font.loadFromFile("./Assets/Fonts/Roboto-Bold.ttf");
    sf::RenderWindow gameWindow(sf::VideoMode(WIDHT_GAMEBOARD_SIZE + 200, HEIGHT_GAMEBOARD_SIZE), "RSnake");

    std::cout << "Welcome to Snake Game" << std::endl;
    RSnakeGame::BlockFactory::Instance()->SetRenderer(&gameWindow);
    RSnakeGame::Board gameBoard{HEIGHT_GAMEBOARD_SIZE, WIDHT_GAMEBOARD_SIZE};
    RSnakeGame::Snake snake{WIDHT_GAMEBOARD_SIZE / 2, HEIGHT_GAMEBOARD_SIZE / 2};
    RSnakeGame::Fruit fruit{WIDHT_GAMEBOARD_SIZE - 2, HEIGHT_GAMEBOARD_SIZE - 2};
    RSnakeGame::ScoreBoard scoreBoard;

    std::unique_ptr<RSnakeGame::IControl> pControl = std::make_unique<RSnakeGame::InputControl>();

    RSnakeGame::Engine GameEngineObj(gameWindow, font, gameBoard, snake, fruit, scoreBoard, std::move(pControl));
    GameEngineObj.GameLoop();

    return 0;
}
