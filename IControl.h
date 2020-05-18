#ifndef ICONTROL_H
#define ICONTROL_H

namespace RSnakeGame
{

struct IControl
{
    ~IControl() {};
    virtual bool isUpPressed()    = 0;
    virtual bool isDownPressed()  = 0;
    virtual bool isLeftPressed()  = 0;
    virtual bool isRightPressed() = 0;
};

}

#endif // ICONTROL_H
