#ifndef ICONTROL_H
#define ICONTROL_H

namespace RSnakeGame
{

struct IControl
{
    virtual bool isUpKeyPressed() = 0;
    virtual bool isUpDownPressed() = 0;
    virtual bool isUpLeftPressed() = 0;
    virtual bool isUpRightPressed() = 0;
};

}

#endif // ICONTROL_H
