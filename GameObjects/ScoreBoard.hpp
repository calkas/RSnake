#pragma once

namespace RSnakeGame
{

class ScoreBoard
{
  public:
    void IncrementScore();
    unsigned int GetScore() const;
    void Reset();

  private:
    unsigned int m_Score{0};
    unsigned int m_Factor{1};
};

} // namespace RSnakeGame
