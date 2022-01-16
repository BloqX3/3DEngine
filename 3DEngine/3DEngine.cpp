// 3DEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ConsoleScreen.h"
#include "Algorithms.h"

int main()
{
    // settings
    ConsoleScreen screen(120, 40);
    screen.Fill();
    //drawLine(&screen, Point(0, 0), Point(5, 5), 'A');
    //
    Vertex v1(0, 0, 0);
    Vertex v2(20, 5, 0);
    Vertex v3(40, 0, 0);
    drawTriangle(&screen, Triangle(&v1, &v2, &v3), 'A');
    // Action
    while (true) {
        screen.Display();
    }
}

