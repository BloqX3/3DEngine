#pragma once
#include "Screen.h"
#include <cmath>

float Distance(Point p1, Point p2, Point p3);
float Pithagors(Point p1);

template<typename T>
void swap(T& lhs, T& rhs) {
    T holder = lhs;
    lhs = rhs;
    rhs = holder;
}

class Vertex {
public:
    float x;
    float y;
    float z;
    Vertex(float X, float Y, float Z);
    operator Point() const { return Point(x, y); }
};

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

#include <iostream>
template<typename T>
void drawLine(IScreen<T>* screen, Point p1, Point p2, T color) {

    Point p = p2 - p1;
    float m = p.y / p.x;
    float length = Pithagors(p);
    
    float xL = 1.0 / sqrt(1.0 + m * m);
    float yL = (std::isinf(m)?1.0: m*xL);

    //float xL = cosf(atanf(m));
    //float yL = sinf(atanf(m));

    //if (p1.y < p2.y && p1.x > p2.x)
    //    swap(p1, p2);

    if (p1.x > p2.x)
        swap(p1, p2);


    for (int i = 0; i < length; i++) {
        screen->setPixel((i * xL + p1.x), (i * yL+ p1.y), color);                                   
    }
}

class Triangle {
public:
    Vertex* a;
    Vertex* b;
    Vertex* c;
    Triangle(Vertex* A, Vertex* B, Vertex* C);
};

template<typename T>
void drawTriangle(IScreen<T>* screen, Triangle triangle, char color) {
    drawLine(screen, *triangle.a, *triangle.b, color);
    drawLine(screen, *triangle.b, *triangle.c, color);
    drawLine(screen, *triangle.c, *triangle.a, color);
}