#pragma once
#include "Algorithms.h"
class IScreen
{
public:
    int Width;
    int Height;
    virtual void Fill() = 0;
    virtual void setPixel(short x, short y, char color) = 0;
    virtual void Display() = 0;
    void drawLine(Point p1, Point p2, char color = 'A');
};