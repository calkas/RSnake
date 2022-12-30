#ifndef INPUTCONTROL_H
#define INPUTCONTROL_H
#include "IControl.h"

namespace RSnakeGame
{
class InputControl : public IControl
{
public:
    virtual bool isUpPressed()    const override;
    virtual bool isDownPressed()  const override;
    virtual bool isLeftPressed()  const override;
    virtual bool isRightPressed() const override;
private:
    bool isKeyPressed(const int key) const;
};

}
#endif // INPUTCONTROL_H
