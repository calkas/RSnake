#ifndef ICONTROL_H
#define ICONTROL_H

namespace RSnakeGame
{

struct IControl
{
    virtual ~IControl() = default;
    virtual bool isUpPressed()    = 0;
    virtual bool isDownPressed()  = 0;
    virtual bool isLeftPressed()  = 0;
    virtual bool isRightPressed() = 0;
};

}

#endif // ICONTROL_H
