#include "Algorithms.h"


#define π 3.14159265358979323846
float toRad(float degree) {
    return degree * π / 180.0;
}

float Pithagors(Point p1)
{
    return sqrt(p1.x * p1.x + p1.y * p1.y);
}

/*Memory overflow!*/
void dotProduct(float** R, Vector3D* vec)
{
    Vector3D res;

    for (int y = 0; y < 3; y++) {
        *res[y] += R[y][0] * vec->x;
        *res[y] += R[y][1] * vec->y;
        *res[y] += R[y][2] * vec->z;
    }
    (*vec) = res;
}

float** Rx(float Θ) {
    float** R = new float* [3];
    R[0] = new float[3] { 1, 0      , 0      };
    R[1] = new float[3] { 0, cosf(Θ),-sinf(Θ)};
    R[2] = new float[3] { 0, sinf(Θ), cosf(Θ)};
    return R;
}
float** Ry(float Θ) {
    float** R = new float* [3];
    R[0] = new float[3]{ cosf(Θ), 0,sinf(Θ) };
    R[1] = new float[3]{ 0      , 1,0       };
    R[2] = new float[3]{ -sinf(Θ),0,cosf(Θ) };
    return R;
}
float** Rz(float Θ) {
    float** R = new float* [3];
    R[0] = new float[3]{ cosf(Θ),-sinf(Θ),0 };
    R[1] = new float[3]{ sinf(Θ), cosf(Θ),0 };
    R[2] = new float[3]{ 0      , 0      ,1 };
    return R;
}

void RotateVector3D(Vector3D* v, float XΘ, float YΘ, float ZΘ){
    dotProduct(Rx(toRad(XΘ)), v);
    dotProduct(Ry(toRad(YΘ)), v);
    dotProduct(Rz(toRad(ZΘ)), v);
}

Vector3D normalizeVector(Vector3D v, float width, float height) {
    return Vector3D((v.x / (v.z + 1) + 0.5) * width, height - (v.y / (v.z + 1) + 0.5) * height , v.z);
}

void RotateZ(Vector3D* v, float newTheta) {
    float a = cosf(toRad(newTheta));
    float b = sinf(toRad(newTheta));

    float x = v->x * a - v->y * b;
    float y = v->x * b + v->y * a;
    v->x = x;
    v->y = y;
}

