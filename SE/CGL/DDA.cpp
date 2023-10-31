#include <iostream>
#include <graphics.h>
using namespace std;

int Round(float x)
{
	if (x - (int)x > 0.5)
	{
		return (int)x + 1;
	}
	else
	{
		return (int)x;
	}
}

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

	float x = x1;
	float y = y1;

	for (int i = 0; i < steps; i++)
	{
		putpixel(Round(x), Round(y), WHITE);
		x += xinc;
		y += yinc;
	}
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	DDA(100, 100, 200, 200);
	getch();
	closegraph();
}