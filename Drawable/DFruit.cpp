#include "DFruit.hpp"
#include <SFML/Graphics.hpp>

namespace RSnakeGame
{

DFruit::DFruit(Point2D coord, int w, int h, sf::RenderWindow *pRenderWindow) : DrawableBlock(coord, w, h, pRenderWindow)
{
}

void DFruit::Draw()
{
    sf::RectangleShape fruit(sf::Vector2f(width, height));
    fruit.move(sf::Vector2f(position.x_f(), position.y_f()));
    fruit.setFillColor(sf::Color::Red);
    pRenderer->draw(fruit);
}

} // namespace RSnakeGame
