#include "ConsoleScreen.h"


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
    for (int l = 0; l < length; l++) screen[l] = '*';
}
void ConsoleScreen::setPixel(short x, short y, char color) {
    screen[y * Width + x] = color;
}
void ConsoleScreen::Display() {
    WriteConsoleOutputCharacter(hConsole, screen, length, { 0,0 }, &dwBytesWritten);
}

