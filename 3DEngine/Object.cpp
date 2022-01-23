#include "Object.h"
#include "Algorithms.h"



Object::Object() {
	Position = Vector3D();
	Rotation = Vector3D();
	R = new Vector3D[3];
	R[0] = Vector3D();
	R[1] = Vector3D();
	R[2] = Vector3D();
}

void Rx(Vector3D* R,float Θ) {
	R[0] = {1, 0      , 0      };
	R[1] = {0, cosf(Θ),-sinf(Θ)};
	R[2] = {0, sinf(Θ), cosf(Θ)};
}
void Ry(Vector3D* R, float Θ) {
	R[0] = { cosf(Θ), 0,sinf(Θ)};
	R[1] = { 0      , 1,0	   };
	R[2] = {-sinf(Θ), 0,cosf(Θ)};
}
void Rz(Vector3D* R, float Θ) {
	R[0] = {cosf(Θ),-sinf(Θ),0 };
	R[1] = {sinf(Θ), cosf(Θ),0 };
	R[2] = {0      , 0      ,1 };
}


Object* Cube(float side)
{
	Object* object = new Object;
	float offset = side / 2.0;

	// vertices
	object->vertices = {
		// Front face
		Vector3D(-offset, -offset,  offset),
		Vector3D(offset, -offset,  offset),
		Vector3D(offset,  offset,  offset),
		Vector3D(-offset,  offset,  offset),

		// Back face
		Vector3D(-offset, -offset, -offset),
		Vector3D(-offset,  offset, -offset),
		Vector3D(offset,  offset, -offset),
		Vector3D(offset, -offset, -offset),

		// Top face
		Vector3D(-offset,  offset, -offset),
		Vector3D(-offset,  offset,  offset),
		Vector3D(offset,  offset,  offset),
		Vector3D(offset,  offset, -offset),

		// Bottom face
		Vector3D(-offset, -offset, -offset),
		Vector3D(offset, -offset, -offset),
		Vector3D(offset, -offset,  offset),
		Vector3D(-offset, -offset,  offset),

		// Right face
		Vector3D(offset, -offset, -offset),
		Vector3D(offset,  offset, -offset),
		Vector3D(offset,  offset,  offset),
		Vector3D(offset, -offset,  offset),

		// Left face
		Vector3D(-offset, -offset, -offset),
		Vector3D(-offset, -offset,  offset),
		Vector3D(-offset,  offset,  offset),
		Vector3D(-offset,  offset, -offset)
	};

	// indices
	object->indices = {
		0,  1,  2,      0,  2,  3,    // front
		4,  5,  6,      4,  6,  7,    // back
		8,  9,  10,     8,  10, 11,   // top
		12, 13, 14,     12, 14, 15,   // bottom
		16, 17, 18,     16, 18, 19,   // right
		20, 21, 22,     20, 22, 23,   // left
	};

	/*Under Construction!*/
	//object->triangles = { 

	//	// front
	//	Triangle(Vector3D(-offset, offset, -offset),
	//			Vector3D(offset, offset, -offset),
	//			Vector3D(offset, -offset, -offset)),
	//	Triangle(Vector3D(offset, -offset, -offset),
	//			Vector3D(-offset, -offset, -offset),
	//			Vector3D(-offset, offset, -offset))
	//	//// back
	//	//Triangle(Vector3D(-offset, offset, offset),
	//	//		Vector3D(offset, offset, offset),
	//	//		Vector3D(-offset, -offset, offset)),
	//	//Triangle(Vector3D(offset, offset, offset),
	//	//		Vector3D(offset, -offset, offset),
	//	//		Vector3D(-offset, -offset, offset)),
	//	//// Top
	//	//Triangle(Vector3D(-offset, offset, -offset),
	//	//		Vector3D(offset, offset, offset),
	//	//		Vector3D(-offset, offset, offset)),
	//	//Triangle(Vector3D(offset, offset, offset),
	//	//		Vector3D(-offset, offset, -offset),
	//	//		Vector3D(offset, offset, -offset)),
	//	//// Bottom
	//	//Triangle(Vector3D(-offset, -offset, -offset),
	//	//		Vector3D(offset, -offset, offset),
	//	//		Vector3D(-offset, -offset, offset)),
	//	//Triangle(Vector3D(offset, -offset, offset),
	//	//		Vector3D(-offset, -offset, -offset),
	//	//		Vector3D(offset, -offset, -offset)),
	//	//// right Sides
	//	//Triangle(Vector3D(offset, -offset, offset),
	//	//		Vector3D(offset, offset, offset),
	//	//		Vector3D(offset, offset, -offset)),
	//	//Triangle(Vector3D(offset, -offset, offset),
	//	//		Vector3D(offset, -offset, -offset),
	//	//		Vector3D(offset, offset, -offset)),
	//	//// left Sides
	//	//Triangle(Vector3D(-offset, -offset, offset),
	//	//		Vector3D(-offset, offset, offset),
	//	//		Vector3D(-offset, offset, -offset)),
	//	//Triangle(Vector3D(-offset, -offset, offset),
	//	//		Vector3D(-offset, -offset, -offset),
	//	//		Vector3D(-offset, offset, -offset)),
	//};

	return object;
}

void Object::setPosition(float x, float y, float z)
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
	Rotation.x = fmod(XΘ, 360);
	Rotation.y = fmod(YΘ, 360);
	Rotation.z = fmod(ZΘ, 360);

}

void Object::ApplyRotation() {
	/* assuming that 3 for loops gives simular performance to 1 loop with 3 opeartions
	*  this arrangent should give better performance and memory optimization due to (R)
	*  incoming feature: dot product of the 3 rotation matrices
	*/

	// Rotate X
	Rx(R, toRad(Rotation.x));
	for (int i = 0; i < vertices.size(); i++) {
		dotProduct(R, &vertices[i]);
	}

	// Rotate Y
	Ry(R, toRad(Rotation.y));
	for (int i = 0; i < vertices.size(); i++) {
		dotProduct(R, &vertices[i]);
	}

	// Rotate Z
	Rz(R, toRad(Rotation.z));
	for (int i = 0; i < vertices.size(); i++) {
		dotProduct(R, &vertices[i]);
	}
}

Vector3D Object::getRotation()
{
	return Rotation;
}
