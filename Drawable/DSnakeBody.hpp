#pragma once
#include "Constans.hpp"
#include "DrawableBlock.hpp"

namespace sf
{
class RenderWindow;
class Shape;
} // namespace sf

namespace RSnakeGame
{

class DSnakeBody : public DrawableBlock
{
  public:
    DSnakeBody(Point2D coord, int w, int h, sf::RenderWindow *pRenderWindow, SnakeBlockType blockType,
               Direction blockDir);
    virtual void SetTexture(sf::Shape *pShape) override;
    virtual void Draw() override;

  private:
    SnakeBlockType m_BlockType;
    Direction m_BlockDirection;
};
} // namespace RSnakeGame
