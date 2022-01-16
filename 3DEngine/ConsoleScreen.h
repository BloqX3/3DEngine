#pragma once
#include "screen.h"
#include <Windows.h>

class ConsoleScreen : public IScreen<char>
{
private:
    int length;
    wchar_t* screen;
    HANDLE hConsole;
    DWORD dwBytesWritten = 0;
public:
    ConsoleScreen(int width, int height);
    void Fill();
    void setPixel(short x, short y, char color);
    void Display();
};

