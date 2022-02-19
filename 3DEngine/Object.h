#pragma once
#include "Core.h"
#include <vector>

/// <summary>
/// Something with position & rotation
/// </summary>
class Actor {
protected:
	Vector3D Position;
	Vector3D Rotation;
	Vector3D worldRotation;
public:
	Actor();
	void Move(float x = 0, float y = 0, float z = 0);
	void setPosition(float x = 0, float y = 0, float z = 0);
	Vector3D* getPosition();

	void Rotate(float XΘ = 0, float YΘ = 0, float ZΘ = 0);
	void setRotation(float XΘ = 0, float YΘ = 0, float ZΘ = 0);
	Vector3D getRotation();
};

/// <summary>
/// an actor with Advance Movements
/// </summary>
class Camera : public Actor {
private:
	Vector3D worldRotation;
public:
	void worldRotate(float XΘ = 0, float YΘ = 0, float ZΘ = 0);
	void setWorldRotation(float XΘ = 0, float YΘ = 0, float ZΘ = 0);
	Vector3D getWorldRotation();

};

/// <summary>
/// a visible Actor (contains indices to 3D points)
/// </summary>
class Object : public Actor
{
public:
	std::vector<Vector3D> vertices;
	std::vector<int> indices;
	void Scale(int scaler);
	void Scale(int x = 0, int y = 0, int z = 0);
};

Object* Cube(float side);
Object* Pyramid(float side);