#pragma once
#include "Constans.hpp"
#include "DrawableObject.hpp"

namespace sf
{
class RenderWindow;
}

namespace RSnakeGame
{
class ObjectFactory
{
  public:
    static ObjectFactory *Instance();
    void SetRenderer(sf::RenderWindow *pRenderWindow);
    std::shared_ptr<DrawableObject> CreateFruit(Point2D coord, int w, int h, float rot, float scale);
    std::shared_ptr<DrawableObject> CreateBoardBlock(Point2D coord, int w, int h, float rot, float scale);
    std::shared_ptr<DrawableObject> CreateSnakeBody(SnakeBlockType snakeBodyType, Point2D coord, int w, int h,
                                                    float rot, float scale, float velocity);

  private:
    ObjectFactory() = default;
    sf::RenderWindow *pRenderer;
};
} // namespace RSnakeGame
