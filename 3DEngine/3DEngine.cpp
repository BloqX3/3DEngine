// 3DEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "World.h"
//#include "ObjLoader.h"

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
    // settings, your console screen must have the same dimensions
    ConsoleScreen screen(110, 45);
    World world(&screen);
    //object loading
    //Object* cube = loadObject("location");
    
    // setting up scene
    Object* cube = Cube(0.5);
    Object* pyramid = Pyramid(0.5);
    world.Spawn(cube);
    world.Spawn(pyramid);
    
    cube->Move(0.25, 0.25);
    pyramid->Move(-0.25, -0.25);

    // pushing back the camera
    world.viewPort->Move(0, 0, -1.5);
    world.FPS = 140;
    // rendering
    while (true) {
        screen.Fill('.');

        // rotating the camera around the origin
        world.viewPort->worldRotate(0, 1);
        world.Render();
    }
}

