#pragma once
#include "DrawableBlock.hpp"

namespace sf
{
class RenderWindow;
}

namespace RSnakeGame
{
class DFruit : public DrawableBlock
{
  public:
    DFruit(int x, int y, int w, int h, sf::RenderWindow *pRenderWindow);
    virtual void Draw() override;
};

} // namespace RSnakeGame
