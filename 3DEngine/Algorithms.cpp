#include "Algorithms.h"


float Distance(Point p1, Point p2, Point p3) {
    //return std::abs(p1.x * p2.y - p1.y * p2.x
    //              + p2.x * p3.y - p2.y * p3.x
    //              + p1.y * p3.x - p1.x * p3.y) 
    //    / std::sqrt((p2.x - p1.x)* (p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
    return std::abs(
        p1.x * (p2.y - p3.y)
        + p2.x * (p3.y - p1.y)
        + p3.x * (p1.y - p2.y))
        / std::sqrt((p3.x - p1.x) * (p3.x - p1.x) + (p3.y - p1.y) * (p3.y - p1.y));

}

float Pithagors(Point p1)
{
    return sqrt(p1.x * p1.x + p1.y * p1.y);
}

Vertex::Vertex(float X, float Y, float Z) {
    x = X;
    y = Y;
    z = Z;
}

Triangle::Triangle(Vertex* A, Vertex* B, Vertex* C) {
    a = A;
    b = B;
    c = C;
}

//template<typename T>
//void drawTriangle(IScreen<T>* screen, Triangle* triangle) {
//    
//}