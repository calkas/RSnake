#pragma once

namespace RSnakeGame
{

class IControl
{
  public:
    virtual ~IControl() = default;
    virtual bool isUpPressed() const = 0;
    virtual bool isDownPressed() const = 0;
    virtual bool isLeftPressed() const = 0;
    virtual bool isRightPressed() const = 0;
};

} // namespace RSnakeGame
