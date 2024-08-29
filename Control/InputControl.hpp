#pragma once
#include "Controllable.hpp"

namespace RSnakeGame
{
class InputControl : public Controllable
{
  public:
    virtual bool isUpPressed() const override;
    virtual bool isDownPressed() const override;
    virtual bool isLeftPressed() const override;
    virtual bool isRightPressed() const override;
};

} // namespace RSnakeGame
