#include "Board.hpp"
#include "Constans.hpp"
#include "DrawableObject.hpp"
#include "Point2d.hpp"
#include <gtest/gtest.h>

TEST(BoardTest, CollisionDetection)
{
    RSnakeGame::Board board;
    Point2D collisionPoint{0, 0};
    auto snakeHead = std::make_shared<RSnakeGame::DrawableObject>(
        collisionPoint, RSnakeGame::Texture::DEFAULT_WIDTH, RSnakeGame::Texture::DEFAULT_HEIGHT, 0.0, 1.0, nullptr);

    EXPECT_TRUE(board.IsCollision(snakeHead));

    snakeHead->position = Point2D{RSnakeGame::Resolution::BOARD_WIDTH, RSnakeGame::Resolution::BOARD_HEIGHT};
    EXPECT_TRUE(board.IsCollision(snakeHead));

    snakeHead->position = Point2D{RSnakeGame::Resolution::BOARD_WIDTH - 1, RSnakeGame::Resolution::BOARD_HEIGHT - 1};
    EXPECT_FALSE(board.IsCollision(snakeHead));
}
