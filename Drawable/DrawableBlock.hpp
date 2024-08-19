#pragma once
#include "Point2d.hpp"
namespace sf
{
class RenderWindow;
class Shape;
} // namespace sf

namespace RSnakeGame
{
class DrawableBlock
{
  public:
    DrawableBlock(Point2D coord, int w, int h, sf::RenderWindow *pRenderWindow)
        : position(coord), width(w), height(h), pRenderer(pRenderWindow)
    {
    }
    virtual ~DrawableBlock() = default;
    virtual void SetTexture(sf::Shape *pShape) = 0;
    virtual void Draw() = 0;
    Point2D position;
    int width, height;
    sf::RenderWindow *pRenderer;
};
} // namespace RSnakeGame
