#pragma once
#include "Point2d.hpp"
#include <memory>
#include <optional>

namespace sf
{
class RenderWindow;
class Texture;
class Shape;
} // namespace sf

namespace RSnakeGame
{
class DrawableObject
{
  public:
    DrawableObject(Point2D coord, int w, int h, float rot, float scale, sf::RenderWindow *pRenderer)
        : position(coord), width(w), height(h), rotation(rot), scale(scale), pRenderer(pRenderer)
    {
    }
    ~DrawableObject() = default;
    void Draw();

    Point2D position;
    int width, height;
    float rotation;
    float scale;
    float velocity{1.0};
    sf::RenderWindow *pRenderer;
    std::optional<std::shared_ptr<sf::Texture>> texture{};
};
} // namespace RSnakeGame
