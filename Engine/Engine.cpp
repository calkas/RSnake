#include "Engine.h"
#include "Board.h"
#include "Snake.h"
#include "Fruit.h"
#include "ScoreBoard.h"
#include "IControl.h"
#include <windows.h>

namespace RSnakeGame
{

Engine::Engine(Board &rBoard, Snake &rSnake, Fruit &rFruit, ScoreBoard &rScoreBoard, std::unique_ptr<IControl> pControl):
    m_rGameBoard(rBoard),
    m_rSnake(rSnake),
    m_rFruit(rFruit),
    m_rScoreBoard(rScoreBoard),
    m_pControl(std::move(pControl)),
    m_GameRunning(true)
{
}

void Engine::GameLoop()
{
    while (m_GameRunning)
    {
        Input();
        HandleObjectCollision();
        if(!m_GameRunning)
        {
            GameOver();
            break;
        }

        Update();
        Draw();
        Sleep(GAME_SPEED);
    }
}

void Engine::Input()
{
    if(m_pControl->isUpPressed())
        m_rSnake.MoveSnake(Snake::SnakeDirection::MOVE_SNAKE_UP);
    else if(m_pControl->isDownPressed())
        m_rSnake.MoveSnake(Snake::SnakeDirection::MOVE_SNAKE_DOWN);
    else if(m_pControl->isLeftPressed())
        m_rSnake.MoveSnake(Snake::SnakeDirection::MOVE_SNAKE_LEFT);
    else if(m_pControl->isRightPressed())
        m_rSnake.MoveSnake(Snake::SnakeDirection::MOVE_SNAKE_RIGHT);
}

void Engine::Update()
{
    m_rFruit.Update();
    m_rSnake.Update();
}

void Engine::Draw()
{
    system("cls");
    m_rGameBoard.Draw();
    m_rSnake.Draw();
    m_rFruit.Draw();
    m_rScoreBoard.Show();
}

void Engine::HandleObjectCollision()
{
    const bool isGameEndCollision = m_rGameBoard.IsCollision(m_rSnake.GetHeadSnakeX(), m_rSnake.GetHeadSnakeY()) ||
            m_rSnake.IsCollision();

    if(isGameEndCollision)
    {
        m_GameRunning = false;
        return;
    }

    if(m_rFruit.WasEaten(m_rSnake.GetHeadSnakeX(), m_rSnake.GetHeadSnakeY()))
    {
        m_rSnake.AddPartOfSnakeBody(m_rSnake.GetHeadSnakeX(), m_rSnake.GetHeadSnakeY());
        m_rScoreBoard.Update();
    }
}

void Engine::GameOver()
{
    system("cls");
    m_rScoreBoard.GameOver();
}
}
