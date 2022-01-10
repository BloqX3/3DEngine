#pragma once

class Point {
public:
    float x;
    float y;
    Point(float X, float Y);
};

float Distance(Point p1, Point p2, Point p3);
void swap(float& lhs, float& rhs);

