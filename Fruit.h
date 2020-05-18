#ifndef FRUIT_H
#define FRUIT_H

namespace RSnakeGame
{
class AObjectShape;

class Fruit
{
public:
    Fruit(int maxGenPosX, int maxGenPosY);
    ~Fruit();

    bool AddFruitShape(AObjectShape *pFruitShape);
    void Update();
    void Draw();
    bool isCollision(int x, int y);

private:
    AObjectShape *m_pFruitShape;
    int m_MaxGenPosX;
    int m_MaxGenPosY;
    bool m_SnakeAteFruitFlag;

    static bool SEEDED_FOR_SRAND;
};
}
#endif // FRUIT_H
