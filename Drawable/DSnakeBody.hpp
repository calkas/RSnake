#pragma once
#include "DrawableBlock.hpp"

namespace sf
{
class RenderWindow;
}

namespace RSnakeGame
{

class DSnakeBody : public DrawableBlock
{
  public:
    DSnakeBody(Point2D coord, int w, int h, sf::RenderWindow *pRenderWindow);
    virtual void Draw() override;
};
} // namespace RSnakeGame
