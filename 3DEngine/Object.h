#pragma once
#include "Core.h"
#include <vector>
/// <summary>
/// Traditional Triangle-based object holder
/// </summary>
class Object
{
private:
	Vector3D Rotation;
	Vector3D Position;
public:
	Object();
	std::vector<Triangle> triangles; 
	//std::vector<int> indices;

	void setPosition(int x, int y, int z);
	Vector3D* getPosition();

	void Rotate(float XΘ, float YΘ, float ZΘ);
	Vector3D getRotation();
};

Object* Cube(float side);
