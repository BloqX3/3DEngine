#pragma once
#include "PipeLine.h"
#include "ConsoleScreen.h"
#include <vector>
#include <chrono>
#include <thread>

template<typename T>
class World
{
private:
	PipeLine<T> renderPipeline;
public:
	std::vector<Object*> Players;
	Camera* viewPort;
	int FPS = 60;
	World(IScreen<T>* screen) {
		viewPort = new Camera();
		renderPipeline.Screen = screen;
	}

	void Spawn(Object* player) {
		Players.push_back(player);
	}
	void Render() {
		// to increase Performance, we calculate the world rotation before rendering the objects
		renderPipeline.setRotation(-viewPort->getRotation(), -viewPort->getWorldRotation());
		for (Object* player : Players) {
			renderPipeline.Render(*player, viewPort->getPosition());
		}
		renderPipeline.Screen->Display();
		// FPS will be optimized for more accurate timing in the future
		std::this_thread::sleep_for(std::chrono::milliseconds(1000/FPS));
	}
	// settings
	void setBackFaceCutting(bool flag) {
		renderPipeline.backFaceCutting = flag;
	}
};


