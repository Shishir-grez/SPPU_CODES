#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;

void DDA(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps;

    if (abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }

    float xinc = (float)dx / steps;
    float yinc = (float)dy / steps;

    int x = x1;
    int y = y1;

    for (int i = 0; i < steps; i++)
    {
        putpixel(round(x), round(y), WHITE);
        x += xinc;
        y += yinc;
    }
}

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
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * x - 4 * y + 10;
        }
        else
        {
            d = d + 4*x + 6;
        }
        drawcircle(xc, yc, x, y);
        delay(50);
    }
}
void pattern1(int xc, int yc, int r)
{
    int x1 = xc; int y1 = yc - r;
    int x2 = xc - r * 0.866; int y2 = yc + r / 2;
    int x3 = xc + r * 0.866; int y3 = yc + r / 2;
    int r1 = r / 2;
    line(x1, y1, x2, y2);
    line(x1, y1, x3, y3);
    line(x2, y2, x3, y3);
    CircleBres(xc, yc, r);
    CircleBres(xc, yc, r1);
}

void pattern2(int x1, int y1, int x2, int y2)
{
    line(x1, y1, x1, y2);
    line(x1, y1, x2, y1);
    line(y2, x2, x2, y1);
    line(x1, y2, x2, y2);

    int x3 = (x1 + x2) / 2;
    int y3 = (y1 + y2) / 2;

    line(x1, y3, x3, y2);
    line(x3, y2, x2, y3);
    line(x2, y3, x3, y1);
    line(x3, y1, x1, y3);

    float theta;

    float xdiff = x2 - x3;
    float ydiff = y2 - y3;

    float xdiffsq = pow(xdiff, 2);
    float ydiffsq = pow(ydiff, 2);

    float lenr = (float) sqrt(xdiffsq + ydiffsq);

    float base = (float)lenr / 2;

    float ratio = (float)base / (y3 - y2);

    theta = (float)acos(ratio);
    
    float radius = (float)(y3 - y2) * sin(theta); // perpendicular

    circle(x3, y3, radius);
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int xc = 200, yc = 200, r = 50;
    pattern2(100, 100, 400,400);
    getch();
    closegraph();
    return 0;
}