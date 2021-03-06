#include "ConsoleScreen.h"
#include <array>

ConsoleScreen::ConsoleScreen(int width, int height) {
    
    Width = width;
    Height = height;
    length = width * height;
    // Create Screen Buffer
    screen = new wchar_t[length];
    
    hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    screen[length - 1] = '\0';
    WriteConsoleOutputCharacter(hConsole, screen, length, { 0,0 }, &dwBytesWritten);
    
}
void ConsoleScreen::Fill() {
    std::fill_n(screen, length, '*');
}
void ConsoleScreen::Fill(char color) {
    std::fill_n(screen, length, color);
}

void ConsoleScreen::setPixel(short x, short y, char color) {
    // if is temporary until clipping is implementing
    if (x < Width && x>=0 && y < Height && y>=0)
    screen[y * Width + x] = color;
}
void ConsoleScreen::Display() {
    WriteConsoleOutputCharacter(hConsole, screen, length, { 0,0 }, &dwBytesWritten);
}

