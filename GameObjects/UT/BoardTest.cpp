#include "Board.hpp"
#include "Constans.hpp"
#include "DrawableObject.hpp"
#include "Point2d.hpp"
#include <gtest/gtest.h>

static constexpr int MaxBoardSizeX{200};
static constexpr int MaxBoardSizeY{100};

TEST(BoardTest, CollisionDetection)
{
    RSnakeGame::Board board{MaxBoardSizeX, MaxBoardSizeY};
    Point2D collisionPoint{0, 190};
    auto snakeHead = std::make_shared<RSnakeGame::DrawableObject>(
        collisionPoint, RSnakeGame::Texture::DEFAULT_WIDTH, RSnakeGame::Texture::DEFAULT_HEIGHT, 0.0, 1.0, nullptr);

    EXPECT_TRUE(board.IsCollision(snakeHead));
}
