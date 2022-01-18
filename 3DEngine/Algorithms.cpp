#include "Algorithms.h"

float Pithagors(Point p1)
{
    return sqrt(p1.x * p1.x + p1.y * p1.y);
}

void RotateVector(Vector3D v, float XΘ, float YΘ, float ZΘ) {

}

Vector3D normalizeVector(Vector3D v, float width, float height) {
    return Vector3D((v.x + 0.5) * width, height - (v.y + 0.5) * height, v.z);
}

#define π 3.14159265358979323846

float toRad(float degree) {
    return degree * π / 180.0;
}

#include <iostream>
void RotateZ(Vector3D* v, float newTheta) {
    //float Z = Pithagors(*v);
    //float theta = atanf(v->y/v->x);
    //v->x = copysignf(cosf(theta + toDegree(newTheta)) * Z, v->x);
    //v->y = copysignf(sinf(theta + toDegree(newTheta)) * Z, v->y);
    //v->x = cosf(theta + newTheta) * Z;
    //v->y = sinf(theta + newTheta) * Z;

    float a = cosf(toRad(newTheta));
    float b = sinf(toRad(newTheta));

    float x = v->x * a - v->y * b;
    float y = v->x * b + v->y * a;
    v->x = x;
    v->y = y;
}

