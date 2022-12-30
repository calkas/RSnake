#include <gtest/gtest.h>
#include "Fruit.h"
#include "Board.h"
#include "Snake.h"

TEST(FruitTest, WasEatenDetection)
{
    RSnakeGame::Fruit fruit(1,1);    
    EXPECT_FALSE(fruit.WasEaten(10,10));
}

TEST(BoardTest, CollistionDetection)
{
    //   0 1 2 3 4
    //0 [][][][][]
    //1 []      []
    //2 []      []
    //3 [][][][][]

    const int WIDHT_GAMEBOARD_SIZE = 5;
    const int HEIGHT_GAMEBOARD_SIZE = 4;

    RSnakeGame::Board board(HEIGHT_GAMEBOARD_SIZE, WIDHT_GAMEBOARD_SIZE);
    EXPECT_TRUE(board.IsCollision(0,2));
    EXPECT_FALSE(board.IsCollision(1,2));
}

TEST(SnakeTest, CreationTest)
{
    //   0 1 2 3 4 5 6 7
    //0 [][][][][][][][]
    //1 []            []
    //2 []  [][][]    []
    //3 []            []
    //4 [][][][][][][][]

    RSnakeGame::Snake snake(2,2);
    EXPECT_EQ(2, snake.GetHeadSnakeX());
    EXPECT_EQ(2, snake.GetHeadSnakeY());
}

TEST(SnakeTest, CollisionDetection)
{
    //   0 1 2 3 4 5 6 7
    //0 [][][][][][][][]
    //1 []            []
    //2 []  [][][]    []
    //3 []            []
    //4 [][][][][][][][]

    RSnakeGame::Snake snake(2,2);
    snake.MoveSnake(RSnakeGame::Snake::SnakeDirection::MOVE_SNAKE_RIGHT);
    snake.Update();
    EXPECT_TRUE(snake.IsCollision());
}

TEST(SnakeTest, MovingDetection)
{
    //   0 1 2 3 4 5 6 7
    //0 [][][][][][][][]
    //1 []            []
    //2 []  [][][]    []
    //3 []            []
    //4 [][][][][][][][]

    RSnakeGame::Snake snake(2,2);
    snake.MoveSnake(RSnakeGame::Snake::SnakeDirection::MOVE_SNAKE_UP);
    snake.Update();
    snake.MoveSnake(RSnakeGame::Snake::SnakeDirection::MOVE_SNAKE_RIGHT);
    snake.Update();
    snake.MoveSnake(RSnakeGame::Snake::SnakeDirection::MOVE_SNAKE_DOWN);
    snake.Update();
    snake.MoveSnake(RSnakeGame::Snake::SnakeDirection::MOVE_SNAKE_DOWN);
    snake.Update();
    snake.MoveSnake(RSnakeGame::Snake::SnakeDirection::MOVE_SNAKE_LEFT);
    snake.Update();

    //   0 1 2 3 4 5 6 7
    //0 [][][][][][][][]
    //1 []            []
    //2 []    []      []
    //3 []  [][]      []
    //4 [][][][][][][][]

    EXPECT_FALSE(snake.IsCollision());
    EXPECT_EQ(2, snake.GetHeadSnakeX());
    EXPECT_EQ(3, snake.GetHeadSnakeY());
}
