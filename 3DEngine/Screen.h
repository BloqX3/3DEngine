#pragma once

#include <Windows.h>
#include <cmath>

class Point {
public:
    float x;
    float y;
    Point(float X, float Y);
};

class Screen
{
private:
    int length;
    int Width;
    int Height;
    wchar_t* screen;
    HANDLE hConsole;
    DWORD dwBytesWritten = 0;
public:
    Screen(int width, int height);
    void Fill();
    void setPixel(short x, short y, char color);
    void Display();
    void drawLine(Point p1, Point p2, char color = 'A');
};