#pragma once

struct Point2D
{
    int x;
    int y;

    float x_f()
    {
        return static_cast<float>(x);
    }
    float y_f()
    {
        return static_cast<float>(y);
    }
};
