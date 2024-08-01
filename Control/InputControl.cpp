#include "InputControl.hpp"
#include <SFML/Window/Keyboard.hpp>

namespace RSnakeGame
{

bool InputControl::isUpPressed() const
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
}

bool InputControl::isDownPressed() const
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
}

bool InputControl::isLeftPressed() const
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
}

bool InputControl::isRightPressed() const
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
}

} // namespace RSnakeGame
