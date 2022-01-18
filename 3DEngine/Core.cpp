#include "Core.h"

Point::Point() {
    x = 0;
    y = 0;
};

Point::Point(float X, float Y) {
    x = X;
    y = Y;
};

Vector3D::Vector3D() {
    x = 0;
    y = 0;
    z = 0;
}

Vector3D::Vector3D(float X, float Y, float Z) {
    x = X;
    y = Y;
    z = Z;
}

Triangle::Triangle(Vector3D A, Vector3D B, Vector3D C) {
    a = A;
    b = B;
    c = C;
}
