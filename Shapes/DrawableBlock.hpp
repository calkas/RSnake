#pragma once

namespace sf
{
class RenderWindow;
}

namespace RSnakeGame
{
class DrawableBlock
{
  public:
    DrawableBlock(int x, int y, int w, int h, sf::RenderWindow *pRenderWindow)
        : posX(x), posY(y), width(w), height(h), pRenderer(pRenderWindow)
    {
    }
    virtual ~DrawableBlock() = default;
    virtual void Draw() = 0;
    int posX, posY, width, height;
    sf::RenderWindow *pRenderer;
};
} // namespace RSnakeGame
