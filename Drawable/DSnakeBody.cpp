#include "DSnakeBody.hpp"
#include <SFML/Graphics.hpp>

namespace RSnakeGame
{

DSnakeBody::DSnakeBody(Point2D coord, int w, int h, sf::RenderWindow *pRenderWindow)
    : DrawableBlock(coord, w, h, pRenderWindow)
{
}

void DSnakeBody::Draw()
{
    sf::RectangleShape snakeBodyElement(sf::Vector2f(width, height));
    snakeBodyElement.move(sf::Vector2f(position.x_f(), position.y_f()));
    snakeBodyElement.setFillColor(sf::Color::Blue);
    pRenderer->draw(snakeBodyElement);
}
} // namespace RSnakeGame
