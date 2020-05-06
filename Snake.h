#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <iostream>

class Snake
{
public:
    Snake();
    ~Snake();

    void AddPartOfBody();
    void Update();

private:
    std::vector<int> m_body;
};

#endif // SNAKE_H
