#include "Algorithms.h"
#include <cmath>

Point::Point(float X, float Y) {
    x = X;
    y = Y;
};

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

void swap(float& lhs, float& rhs) {
    float holder = lhs;
    lhs = rhs;
    rhs = holder;
}
