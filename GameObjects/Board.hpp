#pragma once
#include "DrawableObject.hpp"
#include <memory>
#include <vector>

namespace RSnakeGame
{
class Board
{
  public:
    Board();
    ~Board() = default;
    void Draw() const;
    bool IsCollision(std::shared_ptr<DrawableObject> object) const;

  private:
    void CreateGameBoard();
    void CreateBlock(const int x, const int y);
    std::vector<std::shared_ptr<DrawableObject>> gameMap{};
};
} // namespace RSnakeGame
