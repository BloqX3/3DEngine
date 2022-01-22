#include "Core.h"
#include "Object.h"
#include "Algorithms.h"

template<typename T>
class PipeLine {
public:
	IScreen<T>* Screen;

	void Render(Object player, Vector3D* WorldRoation)
	{
		transformPlayer(&player, WorldRoation);

		Screen->Display();
	}
	void transformPlayer(Object* player, Vector3D* WorldRoation) {
		// Rotation
		player->ApplyRotation();

		// Apply position
		for (int i = 0; i < player->triangles.size();i++) {
			player->triangles[i].a += *player->getPosition();
			player->triangles[i].b += *player->getPosition();
			player->triangles[i].c += *player->getPosition();
		}

		// world Rotation
		player->Rotate(WorldRoation->x, WorldRoation->y, WorldRoation->z);
		player->ApplyRotation();

		for (Triangle triangle : player->triangles) {
			transformTriangle(triangle);
		}

	}
	void transformTriangle(Triangle triangle) {
		// projection
		prespectiveProjectVector(&triangle.a);
		prespectiveProjectVector(&triangle.b);
		prespectiveProjectVector(&triangle.c);

		// normalization
		normalizeVector(&triangle.a, Screen->Width, Screen->Height);
		normalizeVector(&triangle.b, Screen->Width, Screen->Height);
		normalizeVector(&triangle.c, Screen->Width, Screen->Height);

		drawTriangle(Screen, triangle, '#');
	}

};