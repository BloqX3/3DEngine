#pragma once

class Point {
public:
    float x;
    float y;
    Point();
    Point(float X, float Y);
    Point operator + (Point obj) {
        return Point(x + obj.x, y + obj.y);
    }
    Point operator - (Point obj) {
        return Point(x - obj.x, y - obj.y);
    }
};

class Vector3D {
public:
    float x;
    float y;
    float z;
    Vector3D();
    Vector3D(float X, float Y, float Z);
    void operator +=(Vector3D op) { 
        x += op.x;
        y += op.y;
        z += op.z;
    }
    operator Point() const { return Point(x, y); }
    //float operator [](int i) const { return i == 0 ? x : i == 1 ? y : z; }
    float* operator [](int i) { return i == 0 ? &x : i == 1 ? &y : &z; }
};

class Triangle {
public:
    Vector3D a;
    Vector3D b;
    Vector3D c;
    Triangle(Vector3D A, Vector3D B, Vector3D C);
};

template<typename T>
class IScreen 
{
public:
    int Width;
    int Height;
    virtual void Fill() = 0;
    virtual void Fill(T color) = 0;
    virtual void setPixel(short x, short y, T color) = 0;
    virtual void Display() = 0;
};
