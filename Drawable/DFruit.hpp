#pragma once
#include "DrawableBlock.hpp"

namespace sf
{
class RenderWindow;
class Shape;
} // namespace sf

namespace RSnakeGame
{
class DFruit : public DrawableBlock
{
  public:
    DFruit(Point2D coord, int w, int h, sf::RenderWindow *pRenderWindow);
    virtual void SetTexture(sf::Shape *pShape) override;
    virtual void Draw() override;
};

} // namespace RSnakeGame
