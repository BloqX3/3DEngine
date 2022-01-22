// 3DEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ConsoleScreen.h"
#include "Algorithms.h"
#include "Object.h"
#include <chrono>
#include <thread>
#include "World.h"

/* Structure Goal
    World world(&screen);

    Object* cube = Objects.Cube(0.5);

    cube.Vertices[0].Color = ?

    world.Spawn(&cube)
    world.setRenderer(renderTypes.WireFrame);
    world.setShader(Shaders.
    world.setFramrate(60);
    world.enableBackfaceCulling();

    cube.Rotate(30, 30, 30);
    cube.getRotation().x
    cube.setPosition(0,0,0)
    cube.getPosition()->x

    while(true)
        world.Render();
*/

int main()
{
    // settings
    ConsoleScreen screen(110, 45);
    World world(&screen);

    screen.Fill();

    Object* cube = Cube(0.5);
    cube->setPosition(0, 0, 1);

    world.Spawn(cube);
    // Action
    while (true) {
        screen.Fill('.');
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        cube->Rotate(0, cube->getRotation().y + 1, 0);
        
        world.Render();
    }
}

