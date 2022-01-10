#include "Screen.h"


#pragma region Tools

Point::Point(float X, float Y) {
    x = X;
    y = Y;
}

float Distance(Point p1, Point p2, Point p3) {
    //return std::abs(p1.x * p2.y - p1.y * p2.x
    //              + p2.x * p3.y - p2.y * p3.x
    //              + p1.y * p3.x - p1.x * p3.y) 
    //    / std::sqrt((p2.x - p1.x)* (p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
    return std::abs(
        p1.x * (p2.y - p3.y)
        + p2.x * (p3.y - p1.y)
        + p3.x * (p1.y - p2.y))
        / std::sqrt((p3.x - p1.x) * (p3.x - p1.x) + (p3.y - p1.y) * (p3.y - p1.y));

}

void swap(float& lhs, float& rhs) {
    float holder = lhs;
    lhs = rhs;
    rhs = holder;
}
#pragma endregion

#pragma region Screen

Screen::Screen(int width, int height) {
    Width = width;
    length = width * height;
    Height = height;
    // Create Screen Buffer
    screen = new wchar_t[length];
    hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    screen[length - 1] = '\0';
    WriteConsoleOutputCharacter(hConsole, screen, length, { 0,0 }, &dwBytesWritten);

}
void Screen::Fill() {
    for (int x = 0; x < Width; x++)
        for (int y = 0; y < Height; y++)
            screen[y * Width + x] = '*';
}
void Screen::setPixel(short x, short y, char color) {
    screen[y * Width + x] = color;
}
void Screen::Display() {
    WriteConsoleOutputCharacter(hConsole, screen, length, { 0,0 }, &dwBytesWritten);
}
void Screen::drawLine(Point p1, Point p2, char color) {
    if (p1.x > p2.x)
        swap(p1.x, p2.x);
    if (p1.y > p2.y)
        swap(p1.y, p2.y);
    for (int y = p1.y; y <= p2.y; y++) {
        for (int x = p1.x; x <= p2.x; x++) {
            float d = Distance(p1, Point(x, y), p2) + 0.5f;
            if (d <= 1 && d >= 0)
                setPixel(x, y, color);
        }
    }
}

#pragma endregion