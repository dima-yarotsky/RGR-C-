#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "congraphics.h"


int main()
{
	const int n = 20;
	const double a = -1, b = 3;
	double x[n], y1[n], y2[n];
	double y1min = +1e300, y1max = -1e300;
	double y2min = +1e300, y2max = -1e300;
	for (int i = 0; i < n; i++)
	{
		x[i] = a + i * (b - a) / (n - 1);
		y1[i] = 20/(1+pow(x[i],2)); if(y1[i]<y1min) y1min=y1[i]; if(y1[i]>y1max) y1max=y1[i];
		y2[i] =pow((x[i]+5),3)*(1+pow(sin(x[i]),2)); if(y2[i]<y2min) y2min=y2[i]; if(y2[i]>y2max) y2max=y2[i];
	}

	puts("------------------------");
	puts("  x\t  y1 \t y2");
	puts("------------------------");
	for (int i = 0; i < n; i++)
	{
		printf("%.2lg\t", x[i]);
		if(y1[i]==y1min) printf(">"); else if(y1[i]==y1max) printf("<"); else printf(" ");
		printf("%.2lg", y1[i]);
		if(y1[i]==y1min) printf("<"); else if(y1[i]==y1max) printf(">"); else printf(" ");
		printf("\t");
		if(y2[i]==y2min) printf(">"); else if(y2[i]==y2max) printf("<"); else printf(" ");
		printf("%.2lg", y2[i]);
		if(y2[i]==y2min) printf("<"); else if(y2[i]==y2max) printf(">"); else printf(" ");
		printf("\n");
	}
	puts("------------------------");
	_getch();

	// новые массивы точек функций для построения графиков (нужно больше точек, чем n, которое было выше)
	const int m = 1000;
	double xx[m], yy1[m], yy2[m];
	double ymin = +1e300, ymax = -1e300;
	for (int i = 0; i < m; i++)
	{
		xx[i] = a + i * (b - a) / (m - 1);
		yy1[i] = /*sin(xx[i]);*/  20 / (1 + pow(xx[i], 2)); if (yy1[i] < ymin) ymin = yy1[i]; if (yy1[i] > ymax) ymax = yy1[i];
		yy2[i] = /*cos(xx[i]);*/ pow((xx[i] + 5), 3) * (1 + pow(sin(xx[i]), 2)); if (yy2[i] < ymin) ymin = yy2[i]; if (yy2[i] > ymax) ymax = yy2[i];
	}

	system("cls");
	InitGraphics();

	// рисуем оси
	int xxx0 = 20, xxx1 = 420, dxxx = 20, yyy0 = 50, yyy1 = 450, dyyy = 20;
	int yyyz = (int)(ymax * (yyy1 - yyy0 - 2 * dyyy) / (ymax - ymin) + yyy0 + dyyy);
	int xxxz = (int)( - a * (xxx1 - xxx0 - 2 * dxxx) / (b - a) + xxx0 + dxxx);
	SetColor(LIME);
	SetFont(20, 0, 400, true, "Times New Roman");
	Line(xxx0, yyyz, xxx1, yyyz); MoveTo(xxx1 - 5, yyyz - 3); LineTo(xxx1, yyyz); LineTo(xxx1 - 5, yyyz + 3);
	PrintfXY(xxx1 - 15, yyyz - 23, LIME, "x");
	Line(xxxz, yyy0, xxxz, yyy1); MoveTo(xxxz - 3, yyy0 + 5); LineTo(xxxz, yyy0); LineTo(xxxz + 3, yyy0 + 5);
	PrintfXY(xxxz + 8, 35, LIME, "y");

	// рисуем график
	SetFont(14, 0, 400, false, "Verdana");
	PrintfXY(xxx0, yyyz + 2, GREEN, "%.2lf", a);
	PrintfXY(xxx1-30, yyyz + 2, GREEN, "%.2lf", b);
	for (int i = 0; i < m; i++)
	{
		int xg = (int)(xxx0 + dxxx + (xx[i] - a) * (xxx1-xxx0-2*dxxx) / (b - a));
		int yg1 = (int)(yyyz - yy1[i] * (yyy1-yyy0-2*dyyy) / (ymax - ymin));
		int yg2 = (int)(yyyz - yy2[i] * (yyy1-yyy0-2*dyyy) / (ymax - ymin));
		SetPixel(xg, yg1, RED);
		SetPixel(xg, yg2, YELLOW);
	}

	_getch();
	CloseGraphics();
}
