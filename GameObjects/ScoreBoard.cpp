#include "ScoreBoard.hpp"

namespace RSnakeGame
{

void ScoreBoard::IncrementScore()
{
    m_Score += 1 * m_Factor;
    if (m_Score % 10 == 0)
    {
        ++m_Factor;
    }
}
unsigned int ScoreBoard::GetScore() const
{
    return m_Score;
}
} // namespace RSnakeGame
