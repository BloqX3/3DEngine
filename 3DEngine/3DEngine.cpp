// 3DEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ConsoleScreen.h"
#include "Algorithms.h"
#include "Object.h"
#include <chrono>
#include <thread>

/* Structure Goal
    World world(&screen);

    Object* cube = Objects.Cube(0.5);

    cube.Vertices[0].Color = ?

    world.Spawn(&cube)
    world.setRenderer(renderTypes.WireFrame);
    world.setShader(Shaders.
    world.setFramrate(60);

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
    screen.Fill();

    //drawLine(&screen, Point(20, 5), Point(40, 0), 'A');

    Object* cube = Cube(0.5);

    // Action
    while (true) {
        screen.Display();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        screen.Fill('.');
        cube->Rotate(1, 0, 0);

        for (Triangle t : cube->triangles) {
            drawTriangleNormalized(&screen, t, '#');
        }

    }
}

