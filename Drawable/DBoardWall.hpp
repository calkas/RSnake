#pragma once
#include "DrawableBlock.hpp"

namespace sf
{
class RenderWindow;
}

namespace RSnakeGame
{
class DBoardWall : public DrawableBlock
{
  public:
    DBoardWall(Point2D coord, int w, int h, sf::RenderWindow *pRenderWindow);
    virtual void Draw() override;
};

} // namespace RSnakeGame
