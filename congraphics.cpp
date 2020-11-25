#include <stdio.h>
#include <stdarg.h>
#include <windows.h>
#include "congraphics.h"

#define min(a,b) ((a)<(b)?(a):(b))

HWND q;
HDC dc;

int mystrlen(const char *str)
{
	int i=0; for(; str[i]; i++); return i;
}

void InitGraphics()
{
	q = GetConsoleWindow();
    dc = GetDC(q);
}

void SetColor(int COLOR)
{
	SelectObject(dc, GetStockObject(DC_PEN) );
	SetDCPenColor(dc, COLOR);
}

void SetBackgroundColor(int COLOR)
{
	SetBkColor( dc, COLOR );
}

void SetBrushColor(int COLOR)
{
	SelectObject(dc, GetStockObject(DC_BRUSH) );
	SetDCBrushColor(dc, COLOR);
}

void SetPixel(int x, int y, int COLOR)
{
	SetPixel(dc, x, y, COLOR);
}

void Line(int x1, int y1, int x2, int y2)
{
	MoveTo(x1, y1);
    LineTo(x2, y2);
}

void MoveTo(int x, int y)
{
	MoveToEx(dc, x, y, (LPPOINT) NULL);
}

void LineTo(int x, int y)
{			
	LineTo(dc, x, y); 
}

void Ellipse(int left, int top, int right, int bottom)
{
	Ellipse(dc, left, top, right, bottom);
}

void SetFont(int height, int alpha, int weight, bool italic, const char *fontname) 
{ 
    LOGFONTA lf;
	lf.lfHeight = height;
	lf.lfWidth = 0; 
	lf.lfEscapement = alpha; 
	lf.lfOrientation = 0; 
	lf.lfWeight = weight; 
	lf.lfItalic = italic;
	lf.lfUnderline = false;
	lf.lfStrikeOut = false;
	lf.lfCharSet = RUSSIAN_CHARSET;
	lf.lfOutPrecision = OUT_DEFAULT_PRECIS;
	lf.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	lf.lfQuality = ANTIALIASED_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
	if(fontname == NULL) lf.lfFaceName[0] = 0;
	else {
		memcpy(lf.lfFaceName, fontname, min(mystrlen(fontname)+1, 31));
		lf.lfFaceName[31] = 0;
	}

	SelectObject( dc, CreateFontIndirectA(&lf) );
}

void PrintfXY(int x, int y, int COLOR, const char *fmt, ...)
{
	char* buf = new char[mystrlen(fmt)*4];

    va_list args;
    va_start( args, fmt );
	int len = _vscprintf( fmt, args ) + 1;
	vsprintf_s(buf, len, fmt, args);
	va_end(args);	

	SetTextColor( dc, COLOR );
	int prevbkmode = SetBkMode(dc, TRANSPARENT);
	TextOutA( dc, x, y, buf, mystrlen(buf) );
	SetBkMode( dc, prevbkmode);
}

void CloseGraphics()
{
	ReleaseDC(q, dc);
}