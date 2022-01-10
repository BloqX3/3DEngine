#include "Screen.h"

void IScreen::drawLine(Point p1, Point p2, char color) {
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
