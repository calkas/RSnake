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

    void Update();
    void Draw();
    bool isCollision(int x, int y);

private:
    void CreateFruit(int x, int y);
    AObjectShape *m_pFruitShape;
    int m_MaxGenPosX;
    int m_MaxGenPosY;
    bool m_SnakeAteFruitFlag;
    static bool SEEDED_FOR_SRAND;
};
}
#endif // FRUIT_H
