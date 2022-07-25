#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <memory>

namespace RSnakeGame
{
class AObjectShape;

class Board
{
public:
    Board(int height, int widht);
    ~Board();
    void Draw() const;
    bool isCollision(const int x, const int y) const;

private:
    void CreateGameBoard(const int height, const int widht);
    void CreateWall(const int x, const int y);
    std::vector<std::shared_ptr<AObjectShape>> m_Walls;
};
}
#endif // BOARD_H
