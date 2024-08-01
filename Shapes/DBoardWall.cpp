#include "DBoardWall.hpp"
#include <SFML/Graphics.hpp>

namespace RSnakeGame
{

DBoardWall::DBoardWall(int x, int y, int w, int h, sf::RenderWindow *pRenderWindow)
    : DrawableBlock(x, y, w, h, pRenderWindow)
{
}

void DBoardWall::Draw()
{
    sf::RectangleShape wallBrick(sf::Vector2f(width, height));
    wallBrick.move(sf::Vector2f(posX, posY));
    wallBrick.setFillColor(sf::Color::Green);
    pRenderer->draw(wallBrick);
}
} // namespace RSnakeGame
