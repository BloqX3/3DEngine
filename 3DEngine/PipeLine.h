#include "Core.h"
#include "Object.h"
#include "Algorithms.h"

#include <iostream>
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
		for (int i = 0; i < player->vertices.size();i++) {
			player->vertices[i] += *player->getPosition();
		}

		// world Rotation
		player->Rotate(WorldRoation->x, WorldRoation->y, WorldRoation->z);
		player->ApplyRotation();

		for (int i = 0; i < player->indices.size(); i += 3) {
			transformTriangle(Triangle(player->vertices[player->indices[i    ]],
									   player->vertices[player->indices[i + 1]],
									   player->vertices[player->indices[i + 2]])
			);
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
		if (isClockWise(triangle))
			rasterizeTriangle(Screen, triangle, '.');
	}
	/* experimental */
	std::vector<char> Shadows = {
		'-',
		'+',
		'=',
		'#',
	};
	T pixelShader(Triangle triangle) {
		return Shadows[std::fminf(std::abs(Distance(triangle.a, triangle.b, triangle.c))*3.0f, 100.0f)*3.0f/100.0f];
	}

};