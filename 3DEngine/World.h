#pragma once
#include "Core.h"
#include "Object.h"
#include <vector>
#include "PipeLine.h"

template<typename T>
class World
{
private:
	PipeLine<T> renderPipeline;
	Vector3D WorldRotation;
public:
	
	std::vector<Object*> Players;
	World(IScreen<T>* screen) {
		WorldRotation = Vector3D();
		renderPipeline.Screen = screen;
	}
	void Spawn(Object* player) {
		Players.push_back(player);
	}
	void Render() {
		for (Object* player : Players) {
			renderPipeline.Render(*player, &WorldRotation);
		}
	}
	void Rotate(float XΘ, float YΘ, float ZΘ) {
		WorldRotation.x = fmod(XΘ, 360);
		WorldRotation.y = fmod(YΘ, 360);
		WorldRotation.z = fmod(ZΘ, 360);
	}
	Vector3D getRotation() {
		return WorldRotation;
	}
};

