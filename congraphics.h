
void InitGraphics();
void CloseGraphics();

void SetColor(int COLOR);
void SetBackgroundColor(int COLOR);
void SetBrushColor(int COLOR);

void SetPixel(int x, int y, int COLOR);
void MoveTo(int x, int y);
void LineTo(int x, int y);
void Line(int x1, int y1, int x2, int y2);
void Ellipse(int left, int top, int right, int bottom);

void SetFont(int height, int alpha, int weight, bool italic, const char *fontname);
void PrintfXY(int x, int y, int COLOR, const char *fmt, ...);

#define RGB(r,g,b) ((int)(((unsigned char)(r)|((int)((unsigned char)(g))<<8))|(((int)(unsigned char)(b))<<16)))

#define	BLACK	RGB(0, 0, 0)
#define	NAVY	RGB(0, 0, 128)
#define	BLUE	RGB(0, 0, 255)
#define	GREEN	RGB(0, 128, 0)
#define	TEAL	RGB(0, 128, 128)
#define	LIME	RGB(0, 255, 0)
#define	CYAN	RGB(0, 255, 255)
#define	INDIGO	RGB(75, 0, 130)
#define	MAROON	RGB(128, 0, 0)
#define	PURPLE	RGB(128, 0, 128)
#define	OLIVE	RGB(128, 128, 0)
#define	GRAY	RGB(128, 128, 128)
#define	BROWN	RGB(165, 42, 42)
#define	DARKGRAY	RGB(169, 169, 169)
#define	SILVER	RGB(192, 192, 192)
#define	CHOCOLATE	RGB(210, 105, 30)
#define	RED	RGB(255, 0, 0)
#define	MAGENTA	RGB(255, 0, 255)
#define	ORANGE	RGB(255, 165, 0)
#define	PINK	RGB(255, 192, 203)
#define	YELLOW	RGB(255, 255, 0)
#define	WHITE	RGB(255, 255, 255)

