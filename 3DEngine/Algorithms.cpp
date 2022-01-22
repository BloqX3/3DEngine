#include "Algorithms.h"


#define π 3.14159265358979323846
float toRad(float degree) {
    return degree * π / 180.0;
}

float Pithagors(Point p1)
{
    return sqrt(p1.x * p1.x + p1.y * p1.y);
}

void dotProduct(Vector3D* R, Vector3D* vec)
{
    Vector3D res;

    for (int y = 0; y < 3; y++) {
        *res[y] += R[y].x * vec->x;
        *res[y] += R[y].y * vec->y;
        *res[y] += R[y].z * vec->z;
    }
    (*vec) = res;
}

void prespectiveProjectVector(Vector3D* v) {
    v->x = v->x / v->z;
    v->y = v->y / v->z;
}

void normalizeVector(Vector3D* v, float width, float height) {
    v->x = (0.5f + v->x) * width;
    v->y = (0.5f - v->y) * height;
    //return Vector3D(, height - (v->y/ (v->z + 1)  + 0.5) * height , v->z);
}

void RotateZ(Vector3D* v, float newTheta) {
    float a = cosf(toRad(newTheta));
    float b = sinf(toRad(newTheta));

    float x = v->x * a - v->y * b;
    float y = v->x * b + v->y * a;
    v->x = x;
    v->y = y;
}

