#pragma once

class Point {
public:
    float x;
    float y;
    Point(float X, float Y);
    Point operator - (Point obj) {
        return Point(x - obj.x, y - obj.y);
    }
};

template<typename T>
class IScreen
{
public:
    int Width;
    int Height;
    virtual void Fill() = 0;
    virtual void setPixel(short x, short y, T color) = 0;
    virtual void Display() = 0;
};