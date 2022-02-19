#include "Algorithms.h"

float toRad(float degree) {
    return degree * π / 180.0;
}

float Pithagors(Point p1)
{
    return sqrt(p1.x * p1.x + p1.y * p1.y);
}


void dotProduct(Vector3D* Buffer, Vector3D* R1, Vector3D* R2) {
    Vector3D* res = new Vector3D[3];
    for (int i = 0; i < 3; i++) {
        //res[i] = Vector3D(2,2,2);
        res[i].x = R1[i].x * R2[0].x + R1[i].y * R2[1].x + R1[i].z * R2[2].x;
        res[i].y = R1[i].x * R2[0].y + R1[i].y * R2[1].y + R1[i].z * R2[2].y;
        res[i].z = R1[i].x * R2[0].z + R1[i].y * R2[1].z + R1[i].z * R2[2].z;
    }
    Buffer[0] = res[0];
    Buffer[1] = res[1];
    Buffer[2] = res[2];
    delete res;
    //return res;
}

//void dotProduct(Vector3D* R, Vector3D* vec)
//{
//    Vector3D res;
//
//    for (int y = 0; y < 3; y++) {
//        //*res[y] += R[y].x * vec->x;
//        //*res[y] += R[y].y * vec->y;
//        //*res[y] += R[y].z * vec->z;
//    }
//    *vec = res;
//}

void prespectiveProjectVector(Vector3D* v) {
    v->x = v->x / v->z;
    v->y = v->y / v->z;
}

void normalizeVector(Vector3D* v, float width, float height) {
    v->x = (0.5f + v->x) * width;
    v->y = (0.5f - v->y) * height;
    //return Vector3D(, height - (v->y/ (v->z + 1)  + 0.5) * height , v->z);
}

#pragma region Rotation
void getRx(Vector3D* R, float Θ) {
    float sinTheta = sinf(Θ);
    float cosTheta = cosf(Θ);
    R[0] = { 1, 0      , 0         };
    R[1] = { 0, cosTheta,-sinTheta };
    R[2] = { 0, sinTheta, cosTheta };
}
void getRy(Vector3D* R, float Θ) {
    float sinTheta = sinf(Θ);
    float cosTheta = cosf(Θ);
    R[0] = { cosTheta, 0,sinTheta };
    R[1] = { 0       , 1,0        };
    R[2] = {-sinTheta, 0,cosTheta };
}
void getRz(Vector3D* R, float Θ) {
    float sinTheta = sinf(Θ);
    float cosTheta = cosf(Θ);
    R[0] = { cosTheta,-sinTheta,0 };
    R[1] = { sinTheta, cosTheta,0 };
    R[2] = { 0      , 0        ,1 };
}
#pragma endregion

//void RotateZ(Vector3D* v, float newTheta) {
//    float a = cosf(toRad(newTheta));
//    float b = sinf(toRad(newTheta));
//
//    float x = v->x * a - v->y * b;
//    float y = v->x * b + v->y * a;
//    v->x = x;
//    v->y = y;
//}

float Distance(Point p1, Point p2, Point p3) {
    return (
        p1.x * (p2.y - p3.y)
        + p2.x * (p3.y - p1.y)
        + p3.x * (p1.y - p2.y))
        / std::sqrt((p3.x - p1.x) * (p3.x - p1.x) + (p3.y - p1.y) * (p3.y - p1.y));

}
bool isClockWise(Triangle triangle) {
    return Distance(triangle.a, triangle.c, triangle.b) > 0;
}