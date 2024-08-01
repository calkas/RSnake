#ifndef SCOREBOARD_H
#define SCOREBOARD_H

namespace RSnakeGame
{

class ScoreBoard
{
  public:
    ScoreBoard(int posX, int posY);
    void Update();
    void Show();
    void GameOver();

  private:
    unsigned int m_Score;
    int posX;
    int posY;
};

} // namespace RSnakeGame

#endif // SCOREBOARD_H
