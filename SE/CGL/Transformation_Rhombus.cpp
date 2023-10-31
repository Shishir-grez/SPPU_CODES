#include <iostream>
#include <math.h>
#include <graphics.h>
#include <ios>
#include <limits>
using namespace std;

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	initwindow(1920, 1080); // size of graphics window
	// initwindow(1920,1080, ""); // no border
	int a[4][3];

	cout << "Enter x1 and y1 :- ";
	cin >> a[0][0] >> a[0][1];
	cout << "\nEnter x2 and y2 :- ";
	cin >> a[1][0] >> a[1][1];
	cout << "\nEnter x3 and y3 :- ";
	cin >> a[2][0] >> a[2][1];
	cin.ignore();
	cout << "\nEnter x4 and y4 :-";
	cin >> a[3][0] >> a[3][1];
	a[0][2] = a[1][2] = a[2][2] = a[3][2] = 1;

	setcolor(RED);

	line(a[0][0], a[0][1], a[1][0], a[1][1]);
	line(a[0][0], a[0][1], a[2][0], a[2][1]);
	line(a[3][0], a[3][1], a[2][0], a[2][1]);
	line(a[3][0], a[3][1], a[1][0], a[1][1]);
	delay(500);
	cout << "Enter your choice\n1.Translation\n2.Scaling\n3.Rotation";
	int d;
	cin >> d;

	switch (d)
	{
	case 1:
	{
		int b[3][3], c[4][3];
		cout << "\nEnter tx and ty :-";
		cin >> b[2][0] >> b[2][1];
		b[0][0] = b[1][1] = b[2][2] = 1;
		b[1][0] = b[0][1] = b[0][2] = b[1][2] = 0;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				c[i][j] = 0;
				for (int k = 0; k < 3; k++)
				{
					c[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		setcolor(BLUE);
		line(c[0][0], c[0][1], c[1][0], c[1][1]);
		line(c[0][0], c[0][1], c[2][0], c[2][1]);
		line(c[3][0], c[3][1], c[2][0], c[2][1]);
		line(c[3][0], c[3][1], c[1][0], c[1][1]);
		delay(20000);
	}
	break;

	case 2:
	{
		int b[3][3], c[4][3];
		cout << "\nEnter sx and sy :- ";
		cin >> b[0][0] >> b[1][1];
		b[2][2] = 1;
		b[0][1] = b[1][0] = b[2][0] = b[0][2] = b[2][1] = b[0][1] = 0;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				c[i][j] = 0;
				for (int k = 0; k < 3; k++)
				{
					c[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		setcolor(BLUE);
		line(c[0][0], c[0][1], c[1][0], c[1][1]);
		line(c[0][0], c[0][1], c[2][0], c[2][1]);
		line(c[3][0], c[3][1], c[2][0], c[2][1]);
		line(c[3][0], c[3][1], c[1][0], c[1][1]);
		delay(20000);
	}
	break;
	case 3:
	{
		float z, A;
		float b[3][3];
		float c[4][3];
		cout << "\nEnter angle :-";
		cin >> z;

		A = (z * 3.14) / 180;
		b[2][2] = 1;
		b[0][0] = b[1][1] = cos(A);
		b[0][1] = sin(A);
		b[1][0] = (-sin(A));
		b[0][2] = b[1][2] = b[2][0] = b[2][1] = 0;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				c[i][j] = 0;
				for (int k = 0; k < 3; k++)
				{
					c[i][j] += a[i][k] * b[k][j];
				}
			}

		}
		setcolor(BLUE);
		line(c[0][0], c[0][1], c[1][0], c[1][1]);
		line(c[0][0], c[0][1], c[2][0], c[2][1]);
		line(c[3][0], c[3][1], c[2][0], c[2][1]);
		line(c[3][0], c[3][1], c[1][0], c[1][1]);
	}
	break;
	}
	
	getch();
	closegraph();
	return 0;
}
/*
Enter x1 and y1 :- 200 200

Enter x2 and y2 :- 300 200

Enter x3 and y3 :- 250 113

Enter x4 and y4 :-350 113

*/