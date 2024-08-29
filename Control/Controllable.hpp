#pragma once

namespace RSnakeGame
{

class Controllable
{
  public:
    virtual ~Controllable() = default;
    virtual bool isUpPressed() const = 0;
    virtual bool isDownPressed() const = 0;
    virtual bool isLeftPressed() const = 0;
    virtual bool isRightPressed() const = 0;
};

} // namespace RSnakeGame
