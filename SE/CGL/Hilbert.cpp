#include <iostream>
#include <graphics.h>
using namespace std;

void move(int j, int h, int &x, int &y)
{
    if (j == 1)
        y = y - h;
    if (j == 2)
        x = x + h;
    if (j == 3)
        y = y + h;
    if (j == 4)
        x = x - h;
    lineto(x, y);
}

void hilbert(int d, int r, int u, int l, int i, int h, int &x, int &y)
{
    if (i > 0)
    {
        i--;
        hilbert(r, d, l, u, i, h, x, y);
        move(d, h, x, y);
        hilbert(d, r, u, l, i, h, x, y);
        move(r, h, x, y);
        hilbert(d, r, u, l, i, h, x, y);
        move(u, h, x, y);
        hilbert(l, u, r, d, i, h, x, y);
    }
}

int main()
{

    int n;
    int x = 50, y = 150, h = 50, u = 1, r = 2, d = 3, l = 4; // box starting from u
    cout << "Enter the value of n:";
    cin >> n;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    moveto(x, y);
    hilbert(d, r, u, l, n, h, x, y);
    getch();
    closegraph();
    return 0;
}