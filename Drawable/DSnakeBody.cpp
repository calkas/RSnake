#include "DSnakeBody.hpp"
#include <SFML/Graphics.hpp>

namespace RSnakeGame
{

DSnakeBody::DSnakeBody(Point2D coord, int w, int h, sf::RenderWindow *pRenderWindow, SnakeBlockType blockType,
                       Direction blockDir)
    : DrawableBlock(coord, w, h, pRenderWindow), m_BlockType(blockType), m_BlockDirection(blockDir)
{
}

void DSnakeBody::SetTexture(sf::Shape *pShape)
{
    switch (m_BlockType)
    {
    case SnakeBlockType::HEAD:
        pShape->setFillColor(sf::Color::Yellow);
        break;
    case SnakeBlockType::BODY:
        pShape->setFillColor(sf::Color::Blue);
        break;
    case SnakeBlockType::TAIL:
        pShape->setFillColor(sf::Color::Green);
        break;
    }
}

void DSnakeBody::Draw()
{
    sf::RectangleShape snakeBodyElement(sf::Vector2f(width, height));
    snakeBodyElement.move(sf::Vector2f(position.x_f(), position.y_f()));
    SetTexture(&snakeBodyElement);
    pRenderer->draw(snakeBodyElement);
}
} // namespace RSnakeGame
