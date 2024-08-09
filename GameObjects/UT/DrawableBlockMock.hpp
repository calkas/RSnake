#include "DrawableBlock.hpp"
#include <gmock/gmock.h>

namespace RSnakeGame
{
class DrawableBlockMock : public DrawableBlock
{
  public:
    DrawableBlockMock(Point2D coord, int w, int h, sf::RenderWindow *pRenderWindow)
        : DrawableBlock(coord, w, h, pRenderWindow)
    {
    }
    ~DrawableBlockMock() = default;
    MOCK_METHOD(void, Draw, (), (override));
};
} // namespace RSnakeGame
