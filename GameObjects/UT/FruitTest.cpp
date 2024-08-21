#include "Fruit.hpp"
#include "Constans.hpp"
#include "DrawableObject.hpp"
#include "Point2d.hpp"
#include <gmock/gmock.h>
#include <memory>

constexpr int MaxSizeX{3 * RSnakeGame::Texture::DEFAULT_WIDTH + 1};
constexpr int MaxSizeY{3 * RSnakeGame::Texture::DEFAULT_HEIGHT + 1};

TEST(FruitTest, CollisionDetection)
{
    RSnakeGame::Fruit fruit{MaxSizeX, MaxSizeY};
    Point2D collisionPoint{1 + RSnakeGame::Texture::DEFAULT_WIDTH, 1 + RSnakeGame::Texture::DEFAULT_HEIGHT};
    auto snakeHead = std::make_shared<RSnakeGame::DrawableObject>(collisionPoint, RSnakeGame::Texture::DEFAULT_WIDTH,
                                                                  RSnakeGame::Texture::DEFAULT_HEIGHT, 0, 1.0, nullptr);

    EXPECT_TRUE(fruit.WasEaten(snakeHead));
}
