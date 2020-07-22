#ifndef BOARD_H
#define BOARD_H
#include <vector>

namespace RSnakeGame
{
class AObjectShape;
class Board
{
public:
    Board(int height, int widht);
    ~Board();
    void Draw();
    void printAllCoord();
    bool isCollision(int x, int y);

private:
    void CreateGameBoard(int height, int widht);
    void CreateWall(int x, int y);
    std::vector<AObjectShape *> m_VecOfBoardWalls;
};
}
#endif // BOARD_H
