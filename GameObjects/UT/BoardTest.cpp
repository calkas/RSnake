#include "Board.hpp"
#include "DrawableBlock.hpp"
#include "DrawableBlockMock.hpp"
#include "Point2d.hpp"
#include <gtest/gtest.h>

static constexpr int MaxBoardSizeX{200};
static constexpr int MaxBoardSizeY{100};

TEST(BoardTest, CollisionDetection)
{
    RSnakeGame::Board board{MaxBoardSizeX, MaxBoardSizeY};
    Point2D collisionPoint{0, 190};
    std::shared_ptr<RSnakeGame::DrawableBlock> snakeHead =
        std::make_shared<RSnakeGame::DrawableBlockMock>(collisionPoint, 10, 10, nullptr);

    EXPECT_TRUE(board.IsCollision(snakeHead));
}
