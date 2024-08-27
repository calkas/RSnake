#pragma once

struct Point2D
{
    int x;
    int y;

    Point2D() : x(0), y(0)
    {
    }

    Point2D(int x, int y) : x(x), y(y)
    {
    }

    void multiply(int factor_weight, int factor_height)
    {
        x *= factor_weight;
        y *= factor_height;
    }

    Point2D operator+(const Point2D &other)
    {
        return {x + other.x, y + other.y};
    }

    Point2D operator-(const Point2D &other)
    {
        return {x - other.x, y - other.y};
    }

    bool operator==(const Point2D &other)
    {
        return x == other.x && y == other.y;
    }

    float x_f()
    {
        return static_cast<float>(x);
    }
    float y_f()
    {
        return static_cast<float>(y);
    }
};
