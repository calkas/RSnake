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
    int m_PosX;
    int m_PosY;
};

}

#endif // SCOREBOARD_H
