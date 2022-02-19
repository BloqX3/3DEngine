#include "Object.h"
#include "Algorithms.h"

template<typename T>
class PipeLine {
private:
	// Object rotation metrices, changes per rendred object
	Vector3D R[3];
	Vector3D Rn[3];

	// Camera Rotation Metrices, depends on camera roation
	Vector3D cameraR[3];
	Vector3D cameraRn[3];

	// World rotation metrices, dependds on camera world rotation
	Vector3D worldR[3];
	Vector3D worldRn[3];
public:
	IScreen<T>* Screen;
	bool backFaceCutting = true;

	void setRotation(Vector3D cameraRoation, Vector3D worldRoation) {
#pragma region World Rotation Matrices
		// load world rotation Metrices Rx, Ry
		getRx(worldR, toRad(worldRoation.x));
		getRy(worldRn, toRad(worldRoation.y));
		// combine theme and save them in worldR
		dotProduct(worldR, worldR, worldRn);

		// load and combine Rz with theme
		getRz(worldRn, toRad(worldRoation.z));
		dotProduct(worldR, worldR, worldRn);


		// same for camera rotation
		getRx(cameraR, toRad(cameraRoation.x));
		getRy(cameraRn, toRad(cameraRoation.y));
		dotProduct(cameraR, cameraR, cameraRn);

		getRz(cameraRn, toRad(cameraRoation.z));
		dotProduct(cameraR, cameraR, cameraRn);

#pragma endregion
	}

	void Render(Object player, Vector3D* worldPosition)
	{
#pragma region Rotation Matrices
		// load rotation Metrices Rx, Ry
		getRx(R, toRad(player.getRotation().x));
		getRy(Rn, toRad(player.getRotation().y));
		// combine theme and save them in R
		dotProduct(R, R, Rn);

		// load and combine Rz with theme
		getRz(Rn, toRad(player.getRotation().z));
		dotProduct(R, R, Rn);
#pragma endregion

		transformPlayer(&player, worldPosition);
	}

	void transformPlayer(Object* player, Vector3D* worldPosition) {
		// rotations will be optimized in the future
		for (int i = 0; i < player->vertices.size();i++) {			
			player->vertices[i] =
				((player->vertices[i] * R		// Rotate
					+ *player->getPosition())	// Move
					* worldR					// world Rotate
					- *worldPosition)			// Camera Move
					* cameraR;					// Camera rotation

			// Projection
			projectVertix(&player->vertices[i]);

		}

		for (int i = 0; i < player->indices.size(); i += 3) {
			triangleRasterize(Triangle(player->vertices[player->indices[i    ]],
									   player->vertices[player->indices[i + 1]],
									   player->vertices[player->indices[i + 2]])
			);
		}

	}

	void projectVertix(Vector3D* vertix) {
		// prespective projection
		prespectiveProjectVector(vertix);

		// normalization
		// warning: all triangles cordinatates will be flipped (clockwise <-> anti-clockwise)
		normalizeVector(vertix, Screen->Width, Screen->Height);
	}

	void triangleRasterize(Triangle triangle) {
		if (!backFaceCutting || isClockWise(triangle))
			drawTriangle(Screen, triangle, '#');
	}
	/* experimental */
	std::vector<char> Shadows = {
		
		'-',
		'+',
		'=',
		'#',
	};
	T pixelShader(Triangle triangle) {
		return Shadows[std::fminf(std::abs(Distance(triangle.a, triangle.b, triangle.c))*2.0f, 100.0f)* (Shadows.size()-1) / 100.0f];
	}

};