// 3DEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ConsoleScreen.h"

int main()
{
    // settings
    ConsoleScreen screen(120, 40);
    screen.Fill();
    screen.drawLine(Point(3, 5), Point(0, 0));
    // Action
    while (true) {
        screen.Display();
    }
   
}

