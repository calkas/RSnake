#include "DrawableObject.hpp"
#include <SFML/Graphics.hpp>

namespace RSnakeGame
{
void DrawableObject::Draw()
{
    sf::RectangleShape shape(sf::Vector2f(width, height));
    // Set the origin to the center of the shape
    shape.setOrigin(width / 2.0f, height / 2.0f);

    // Move the shape to the correct position
    shape.setPosition(sf::Vector2f(position.x_f(), position.y_f()));

    if (!texture.has_value())
    {
        shape.setFillColor(sf::Color::Blue);
        pRenderer->draw(shape);
        return;
    }
    texture.value()->setSmooth(true);
    shape.setTexture(texture.value().get());
    sf::FloatRect bounds = shape.getLocalBounds();
    shape.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
    shape.setRotation(rotation);
    shape.setScale(scale, scale);
    pRenderer->draw(shape);
}

} // namespace RSnakeGame
