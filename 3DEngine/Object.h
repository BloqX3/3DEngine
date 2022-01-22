#pragma once
#include "Core.h"
#include <vector>
/// <summary>
/// Traditional Triangle-based object holder
/// </summary>

void Rx(Vector3D* R, float Θ);
void Ry(Vector3D* R, float Θ);
void Rz(Vector3D* R, float Θ);

class Object
{
private:
	Vector3D Rotation;
	Vector3D Position;
public:
	Vector3D* R;
	Object();
	std::vector<Triangle> triangles; 
	//std::vector<int> indices;

	void setPosition(float x, float y, float z);
	Vector3D* getPosition();

	void Rotate(float XΘ, float YΘ, float ZΘ);
	void ApplyRotation();
	Vector3D getRotation();
};

Object* Cube(float side);
