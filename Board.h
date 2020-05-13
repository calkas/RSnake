#ifndef BOARD_H
#define BOARD_H
#include <vector>

namespace RSnakeGame
{
class AObjectShape;
class Board
{
public:
    Board();
    ~Board();

    bool AddBoardWall(AObjectShape *pWall);
    void Draw();

    void printAllCoord();

    bool isCollision(int x, int y);

private:
    std::vector<AObjectShape *> m_VecOfBoardWalls;
};
}
#endif // BOARD_H
