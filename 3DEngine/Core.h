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
    void operator -=(Vector3D op) {
        x -= op.x;
        y -= op.y;
        z -= op.z;
    }
    Vector3D operator +(Vector3D rhs) {
        Vector3D res;
        res.x = x + rhs.x;
        res.y = y + rhs.y;
        res.z = z + rhs.z;
        return res;
    }
    Vector3D operator -(Vector3D rhs) {
        Vector3D res;
        res.x = x - rhs.x;
        res.y = y - rhs.y;
        res.z = z - rhs.z;
        return res;
    }

    Vector3D const operator -() {
        Vector3D res;
        res.x = -x;
        res.y = -y;
        res.z = -z;

        return res;
    }

    operator Point() const { return Point(x, y); }
    float operator [](int i) const { return i == 0 ? x : i == 1 ? y : z; }
    //float* operator [](int i) { return i == 0 ? &x : i == 1 ? &y : &z; }
    // Dot Product, lhs is a 3x3 vector3D array
    Vector3D operator *(Vector3D* lhs) {
        Vector3D res;
        for (int i = 0; i < 3; i++) {
            res.x += (*this)[i] * lhs[0][i];
            res.y += (*this)[i] * lhs[1][i];
            res.z += (*this)[i] * lhs[2][i];
        }
        return res;
    }
};
template<typename T>
class Vertex {
public:
    Vector3D position;
    T color;
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
