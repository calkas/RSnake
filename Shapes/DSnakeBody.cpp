#include "DSnakeBody.hpp"
#include <SFML/Graphics.hpp>

namespace RSnakeGame
{

DSnakeBody::DSnakeBody(int x, int y, int w, int h, sf::RenderWindow *pRenderWindow)
    : DrawableBlock(x, y, w, h, pRenderWindow)
{
}

void DSnakeBody::Draw()
{
    sf::RectangleShape snakeBodyElement(sf::Vector2f(width, height));
    snakeBodyElement.move(sf::Vector2f(posX, posY));
    snakeBodyElement.setFillColor(sf::Color::Blue);
    pRenderer->draw(snakeBodyElement);
}
} // namespace RSnakeGame
