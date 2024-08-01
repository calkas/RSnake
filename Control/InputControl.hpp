#pragma once
#include "IControl.hpp"

namespace RSnakeGame
{
class InputControl : public IControl
{
  public:
    virtual bool isUpPressed() const override;
    virtual bool isDownPressed() const override;
    virtual bool isLeftPressed() const override;
    virtual bool isRightPressed() const override;
};

} // namespace RSnakeGame
