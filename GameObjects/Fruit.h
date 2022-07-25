#ifndef FRUIT_H
#define FRUIT_H

#include <memory>

namespace RSnakeGame
{
class AObjectShape;

class Fruit
{
public:
    Fruit(int maxGenPosX, int maxGenPosY);
    // This destructor is needed
    //https://developpaper.com/stdunique_-analysis-and-solution-of-error-reporting-using-incomplete-type-in-ptr/
    ~Fruit();

    void Update();
    void Draw() const;
    bool isCollision(const int x, const int y);

private:
    void CreateFruit(const int x, const int y);
    std::unique_ptr<AObjectShape> m_pFruit;
    int m_MaxGenPosX;
    int m_MaxGenPosY;
    bool m_SnakeAteFruitFlag;
    static bool SEEDED_FOR_SRAND;
};
}
#endif // FRUIT_H
