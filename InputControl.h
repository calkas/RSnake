#ifndef INPUTCONTROL_H
#define INPUTCONTROL_H
#include "IControl.h"

namespace RSnakeGame
{
class InputControl : public IControl
{
public:
    virtual bool isUpPressed()    override;
    virtual bool isDownPressed()  override;
    virtual bool isLeftPressed()  override;
    virtual bool isRightPressed() override;
private:
    bool isKeyPressed(int key);
};

}
#endif // INPUTCONTROL_H
