#include "Snake.hpp"
#include "Constans.hpp"
#include "Point2d.hpp"
#include <gtest/gtest.h>

static Point2D StartPoint{100, 150};
TEST(SnakeTest, CreationTest)
{
    RSnakeGame::Snake snake{StartPoint.x, StartPoint.y};

    EXPECT_EQ(StartPoint.x, snake.GetHead().get()->position.x);
    EXPECT_EQ(StartPoint.y, snake.GetHead().get()->position.y);
}

TEST(SnakeTest, CollisionDetection)
{
    RSnakeGame::Snake snake{StartPoint.x, StartPoint.y};

    EXPECT_FALSE(snake.IsCollision());

    snake.AddBodyElement();
    snake.AddBodyElement();
    snake.AddBodyElement();
    snake.Move(RSnakeGame::Direction::UP);
    snake.Update();
    snake.Move(RSnakeGame::Direction::RIGHT);
    snake.Update();
    snake.Move(RSnakeGame::Direction::DOWN);
    snake.Update();

    EXPECT_TRUE(snake.IsCollision());
}
