#include "DBoard.hpp"
#include <SFML/Graphics.hpp>

namespace RSnakeGame
{

DBoard::DBoard(Point2D coord, int w, int h, sf::RenderWindow *pRenderWindow) : DrawableBlock(coord, w, h, pRenderWindow)
{
}

void DBoard::SetTexture(sf::Shape *pShape)
{
}

void DBoard::Draw()
{
    sf::RectangleShape wallBrick(sf::Vector2f(width, height));
    wallBrick.move(sf::Vector2f(position.x_f(), position.y_f()));
    wallBrick.setFillColor(sf::Color::Green);
    pRenderer->draw(wallBrick);
}
} // namespace RSnakeGame
