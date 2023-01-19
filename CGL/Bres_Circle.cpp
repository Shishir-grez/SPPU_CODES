#include <iostream>
#include <graphics.h>
using namespace std;

void drawcircle(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);

    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void CircleBres(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;

    drawcircle(xc, yc, x, y);
    while (y >= x)
    {
        if (d > 0)
        {
            y--;
            d = d + 4 * x - 4 * y + 10;
        }
        else
        {
            d = d + 4 * x + 6;
        }
        drawcircle(xc, yc, x, y);
        delay(50);
        x++;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int xc = 200, yc = 200, r = 50;
    CircleBres(xc, yc, r);
    getch();
    closegraph();
    return 0;
}