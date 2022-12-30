#ifndef ICONTROL_H
#define ICONTROL_H

namespace RSnakeGame
{

struct IControl
{
    virtual ~IControl() = default;
    virtual bool isUpPressed()    const  = 0;
    virtual bool isDownPressed()  const  = 0;
    virtual bool isLeftPressed()  const  = 0;
    virtual bool isRightPressed() const  = 0;
};

}

#endif // ICONTROL_H
