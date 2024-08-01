#include "DFruit.hpp"
#include <SFML/Graphics.hpp>

namespace RSnakeGame
{

DFruit::DFruit(int x, int y, int w, int h, sf::RenderWindow *pRenderWindow) : DrawableBlock(x, y, w, h, pRenderWindow)
{
}

void DFruit::Draw()
{
    sf::RectangleShape fruit(sf::Vector2f(width, height));
    fruit.move(sf::Vector2f(posX, posY));
    fruit.setFillColor(sf::Color::Red);
    pRenderer->draw(fruit);
}

} // namespace RSnakeGame
