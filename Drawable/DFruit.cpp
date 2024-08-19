#include "DFruit.hpp"
#include <SFML/Graphics.hpp>

namespace RSnakeGame
{

DFruit::DFruit(Point2D coord, int w, int h, sf::RenderWindow *pRenderWindow) : DrawableBlock(coord, w, h, pRenderWindow)
{
}

void DFruit::SetTexture(sf::Shape *pShape)
{
    pShape->setFillColor(sf::Color::Red);
}

void DFruit::Draw()
{
    sf::RectangleShape fruit(sf::Vector2f(width, height));
    fruit.move(sf::Vector2f(position.x_f(), position.y_f()));
    SetTexture(&fruit);
    pRenderer->draw(fruit);
}

} // namespace RSnakeGame
