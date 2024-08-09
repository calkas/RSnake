#include "Snake.hpp"
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

    snake.AddBodyElement();
    snake.AddBodyElement();
    snake.AddBodyElement();
    snake.Move(RSnakeGame::Snake::Direction::UP);
    snake.Update();
    snake.Move(RSnakeGame::Snake::Direction::RIGHT);
    snake.Update();
    snake.Move(RSnakeGame::Snake::Direction::DOWN);
    snake.Update();

    EXPECT_TRUE(snake.IsCollision());
}

TEST(SnakeTest, MovingDetection)
{
    RSnakeGame::Snake snake{StartPoint.x, StartPoint.y};

    snake.Move(RSnakeGame::Snake::Direction::UP);
    snake.Update();
    snake.Move(RSnakeGame::Snake::Direction::RIGHT);
    snake.Update();
    snake.Move(RSnakeGame::Snake::Direction::DOWN);
    snake.Update();
    snake.Move(RSnakeGame::Snake::Direction::DOWN);
    snake.Update();

    EXPECT_FALSE(snake.IsCollision());
    EXPECT_EQ(110, snake.GetHead().get()->position.x);
    EXPECT_EQ(160, snake.GetHead().get()->position.y);
}
