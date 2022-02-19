#pragma once
#include "Core.h"
#include <cmath>

#define π 3.14159265358979323846
float toRad(float rad);
float Pithagors(Point p1);
/// <summary>
/// returns the dot product of two 3x3 Vector3D array
/// </summary>
/// <param name="R1">3x3 Vector3D aray</param>
/// <param name="R2">3x3 Vector3D aray</param>
void dotProduct(Vector3D* Buffer, Vector3D* R1, Vector3D* R2);
void prespectiveProjectVector(Vector3D* v);
void normalizeVector(Vector3D* v, float width, float height);

float Distance(Point p1, Point p2, Point p3);

template<typename T>
void swap(T& lhs, T& rhs) {
    T holder = lhs;
    lhs = rhs;
    rhs = holder;
}

//template<typename T>
//void drawLine(IScreen<T>* screen, Point p1, Point p2, T color) {
//    //if (p1.x > p2.x)
//    //    swap(p1.x, p2.x);
//    //if (p1.y > p2.y)
//    //    swap(p1.y, p2.y);
//    //if (p1.y > p2.y || p1.x > p2.x)
//    //    swap(p1, p2);
//    for (int y = 0; y <= p2.y-p1.y; y++) {
//        for (int x = 0; x <= p2.x- p1.x; x++) {
//            float d = Distance(p1, Point(x, y), p2) + 0.5f;
//            if (d <= 1 && d >= 0)
//                screen->setPixel(x + p1.x, y, color);
//        }
//    }
//}

bool isClockWise(Triangle triangle);

#pragma region Rotation
void getRx(Vector3D* R, float Θ);
void getRy(Vector3D* R, float Θ);
void getRz(Vector3D* R, float Θ);
#pragma endregion

#pragma region DrawingAlgorithms
template<typename T>
void drawLine(IScreen<T>* screen, Point p1, Point p2, T color) {

    Point p = p2 - p1;
    float m = p.y / p.x;
    float length = Pithagors(p);
    
    float xL = 1.0f / sqrtf(1.0f + m * m);
    float yL = (std::isinf(m)?1.0f: m*xL);

    if (p1.x > p2.x || (p1.x == p2.x) && p1.y > p2.y)
        swap(p1, p2);

    for (int i = 0; i < length; i++) {
        screen->setPixel((i * xL + p1.x), (i * yL+ p1.y), color);                                   
    }
}

template<typename T>
void drawTriangle(IScreen<T>* screen, Triangle triangle, T color) {
    drawLine(screen, triangle.a, triangle.b, color);
    drawLine(screen, triangle.b, triangle.c, color);
    drawLine(screen, triangle.c, triangle.a, color);
}

template<typename T>
void rasterizeTriangle(IScreen<T>* screen, Triangle triangle, T color) {
    Point p1 = triangle.a;
    Point p2 = triangle.b;

    Point p = p2 - p1;
    float m = p.y / p.x;
    float length = Pithagors(p);

    float xL = 1.0f / sqrtf(1.0f + m * m);
    float yL = (std::isinf(m) ? 1.0f : m * xL);

    if (p1.x > p2.x || (p1.x == p2.x) && p1.y > p2.y)
        swap(p1, p2);

    for (int i = 0; i < length; i++) {
        Point pn((i * xL + p1.x), (i * yL + p1.y));

        drawLine(screen, pn, triangle.c, color);
        //screen->setPixel(x, y, color);

    }
}
#pragma endregion