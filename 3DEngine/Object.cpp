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

	};
	object->setPosition(2, 2, 2);

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
		RotateZ(&triangles[i].a, XΘ);
		RotateZ(&triangles[i].b, XΘ);
		RotateZ(&triangles[i].c, XΘ);
	}
}

Vector3D Object::getRotation()
{
	return Rotation;
}
