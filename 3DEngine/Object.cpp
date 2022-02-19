#include "Object.h"
#include "Algorithms.h"

Actor::Actor() {
	Position = Vector3D();
	Rotation = Vector3D();
	worldRotation = Vector3D();
}

//Object::Object() {
//	Position = Vector3D();
//	Rotation = Vector3D();
//	worldRotation = Vector3D();
//}


//Camera::Camera()
//{
//	Position = Vector3D();
//	Rotation = Vector3D();
//	worldRotation = Vector3D();
//}

void Camera::worldRotate(float XΘ, float YΘ, float ZΘ)
{
	worldRotation.x = fmod(worldRotation.x + XΘ, 360);
	worldRotation.y = fmod(worldRotation.y + YΘ, 360);
	worldRotation.z = fmod(worldRotation.z + ZΘ, 360);
}

void Camera::setWorldRotation(float XΘ, float YΘ, float ZΘ)
{
	worldRotation.x = fmod(XΘ, 360);
	worldRotation.y = fmod(YΘ, 360);
	worldRotation.z = fmod(ZΘ, 360);
}

Vector3D Camera::getWorldRotation()
{
	return worldRotation;
}


void Object::Scale(int scaler)
{
	Position = { Position.x * scaler,
				Position.y * scaler,
				Position.z * scaler };
}

void Object::Scale(int x, int y, int z)
{
	Position.x *= x;
	Position.y *= y;
	Position.z *= z;
}

void Actor::Move(float x, float y, float z) {
	Position.x += x;
	Position.y += y;
	Position.z += z;
}

void Actor::setPosition(float x, float y, float z)
{
	Position = { x ,y ,z };
}

Vector3D* Actor::getPosition()
{
	return &Position;
}


void Actor::Rotate(float XΘ, float YΘ, float ZΘ)
{
	Rotation.x = fmod(Rotation.x + XΘ, 360);
	Rotation.y = fmod(Rotation.y + YΘ, 360);
	Rotation.z = fmod(Rotation.z + ZΘ, 360);
}

void Actor::setRotation(float XΘ, float YΘ, float ZΘ) {
	Rotation = {(float)fmod(XΘ, 360),
				(float)fmod(YΘ, 360),
				(float)fmod(ZΘ, 360) };
}

Vector3D Actor::getRotation()
{
	return Rotation;
}



Object* Cube(float side)
{
	Object* object = new Object;
	float offset = side / 2.0;

	// vertices
	object->vertices = {
		// Front
		Vector3D(-offset,  offset,  -offset), // top left
		Vector3D(offset,  offset,  -offset),  // top right
		Vector3D(-offset, -offset,  -offset), // bottom left
		Vector3D(offset, -offset,  -offset),  // bottom right

		// Back
		Vector3D(-offset,  offset,  offset), // top left
		Vector3D(offset,  offset,  offset),  // top right
		Vector3D(-offset, -offset,  offset), // bottom left
		Vector3D(offset, -offset,  offset),  // bottom right
	};

	// indices
	object->indices = {
		1, 0, 3,  0, 2, 3,  // front face
		4, 7, 6,  4, 5, 7,  // back face
		0, 4, 6,  0, 6, 2,  // left face
		5, 1, 3,  3, 7, 5,  // right face
		0, 1, 5,  0, 5, 4,  // top face
		3, 2, 7,  2, 6, 7,  // bottom face
	};

	return object;
}

Object* Pyramid(float side)
{
	Object* object = new Object;
	float offset = side / 2.0;

	// vertices
	object->vertices = {
		// top
		Vector3D(0.0,offset,0.0),

		// front
		Vector3D(-offset,-offset,-offset), // bottom left
		Vector3D(offset,-offset,-offset),  // bottom right

		// back
		Vector3D(-offset,-offset,offset), // bottom left
		Vector3D(offset,-offset,offset),  // bottom right
	};

	object->indices = {
		0, 1, 2,
		0, 3, 1,
		0, 2, 4,
		0, 4, 3,
		1, 3, 4,
		1, 4, 2
	};
	return object;
}

