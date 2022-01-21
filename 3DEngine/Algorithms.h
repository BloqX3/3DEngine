#pragma once
#include "Core.h"
#include <cmath>

float toRad(float rad);
float Pithagors(Point p1);
void dotProduct(float** R, Vector3D* vec);
//void RotatePoint(Point v, float XΘ, float YΘ, float ZΘ);
void RotateVector3D(Vector3D* v, float XΘ, float YΘ, float ZΘ);
void RotateZ(Vector3D* v, float newTheta);
Vector3D normalizeVector(Vector3D v, float width, float height);

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


template<typename T>
void drawLine(IScreen<T>* screen, Point p1, Point p2, T color) {

    Point p = p2 - p1;
    float m = p.y / p.x;
    float length = Pithagors(p);
    
    float xL = 1.0 / sqrt(1.0 + m * m);
    float yL = (std::isinf(m)?1.0: m*xL);

    if (p1.x > p2.x || (p1.x == p2.x) && p1.y > p2.y)
        swap(p1, p2);

    for (int i = 0; i < length; i++) {
        screen->setPixel((i * xL + p1.x), (i * yL+ p1.y), color);                                   
    }
}


template<typename T>
void drawTriangle(IScreen<T>* screen, Triangle triangle, char color) {
    drawLine(screen, triangle.a, triangle.b, color);
    drawLine(screen, triangle.b, triangle.c, color);
    drawLine(screen, triangle.c, triangle.a, color);
}

template<typename T>
void drawTriangleNormalized(IScreen<T>* screen, Triangle triangle, char color) {
    triangle.a = normalizeVector(triangle.a, screen->Width, screen->Height);
    triangle.b = normalizeVector(triangle.b, screen->Width, screen->Height);
    triangle.c = normalizeVector(triangle.c, screen->Width, screen->Height);
    drawLine(screen, triangle.a, triangle.b, color);
    drawLine(screen, triangle.b, triangle.c, color);
    drawLine(screen, triangle.c, triangle.a, color);
}