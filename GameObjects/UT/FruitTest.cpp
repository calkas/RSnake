#include "Fruit.hpp"
#include "DrawableBlock.hpp"
#include "DrawableBlockMock.hpp"
#include "Point2d.hpp"
#include <gmock/gmock.h>
#include <memory>

static constexpr int MaxSizeX{31};
static constexpr int MaxSizeY{31};

TEST(FruitTest, CollisionDetection)
{
    RSnakeGame::Fruit fruit{MaxSizeX, MaxSizeY};
    Point2D collisionPoint{11, 11};
    std::shared_ptr<RSnakeGame::DrawableBlock> snakeHead =
        std::make_shared<RSnakeGame::DrawableBlockMock>(collisionPoint, 10, 10, nullptr);

    EXPECT_TRUE(fruit.WasEaten(snakeHead));
}
