#include "Object.h"
#include "Algorithms.h"

Object::Object() {
	Position = Vector3D();
	Rotation = Vector3D();
}

Object* Cube(float side)
{
	Object* object = new Object;
	float offset = side / 2.0;
	/*Under Construction!*/
	object->triangles = { 
		// front
		Triangle(Vector3D(-offset, offset, offset),
				Vector3D(offset, offset, offset),
				Vector3D(-offset, -offset, offset)),
		Triangle(Vector3D(offset, offset, offset),
				Vector3D(offset, -offset, offset),
				Vector3D(-offset, -offset, offset)),

		// back
		Triangle(Vector3D(-offset, offset, -offset),
				Vector3D(offset, offset, -offset),
				Vector3D(-offset, -offset, -offset)),
		Triangle(Vector3D(offset, offset, -offset),
				Vector3D(offset, -offset, -offset),
				Vector3D(-offset, -offset, -offset)),

		// Top
		Triangle(Vector3D(-offset, offset, -offset),
				Vector3D(offset, offset, offset),
				Vector3D(-offset, offset, offset)),
		Triangle(Vector3D(offset, offset, offset),
				Vector3D(-offset, offset, -offset),
				Vector3D(offset, offset, -offset)),
		// Bottom
		Triangle(Vector3D(-offset, -offset, -offset),
				Vector3D(offset, -offset, offset),
				Vector3D(-offset, -offset, offset)),
		Triangle(Vector3D(offset, -offset, offset),
				Vector3D(-offset, -offset, -offset),
				Vector3D(offset, -offset, -offset)),

		// right Sides
		Triangle(Vector3D(offset, -offset, offset),
				Vector3D(offset, offset, offset),
				Vector3D(offset, offset, -offset)),
		Triangle(Vector3D(offset, -offset, offset),
				Vector3D(offset, -offset, -offset),
				Vector3D(offset, offset, -offset)),

		// left Sides
		Triangle(Vector3D(-offset, -offset, offset),
				Vector3D(-offset, offset, offset),
				Vector3D(-offset, offset, -offset)),
		Triangle(Vector3D(-offset, -offset, offset),
				Vector3D(-offset, -offset, -offset),
				Vector3D(-offset, offset, -offset)),
	};

	return object;
}

void Object::setPosition(int x, int y, int z)
{
	Position.x = x;
	Position.y = y;
	Position.z = z;
}

Vector3D* Object::getPosition()
{
	return &Position;
}

void Object::Rotate(float XΘ, float YΘ, float ZΘ) {
	for (int i = 0; i < triangles.size();i++) {
		RotateVector3D(&triangles[i].a, XΘ, YΘ, ZΘ);
		RotateVector3D(&triangles[i].b, XΘ, YΘ, ZΘ);
		RotateVector3D(&triangles[i].c, XΘ, YΘ, ZΘ);
	}
}

Vector3D Object::getRotation()
{
	return Rotation;
}
