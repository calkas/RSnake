#pragma once
#include "DrawableObject.hpp"
#include <memory>
#include <vector>

namespace RSnakeGame
{
class Board
{
  public:
    Board(int height, int width);
    ~Board();
    void Draw() const;
    bool IsCollision(std::shared_ptr<DrawableObject> object) const;

    int m_height;
    int m_width;

  private:
    void CreateGameBoard(const int height, const int width);
    void CreateWallBlock(const int x, const int y);
    std::vector<std::shared_ptr<DrawableObject>> m_Walls;
};
} // namespace RSnakeGame
