// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// msoftcon.h
// Объявления функций консольной графики от Роберта Лафоре
// (в них используются консольные функции Windows)

#ifndef _INC_WCONSOLE // этот файл не должен включаться
#define _INC_WCONSOLE // дважды в тот же исходный файл

#include <windows.h> // для консольных функций, констант и типов Windows
#include <conio.h>   // для _putwch, _cputws
#include <math.h>    // для sin, cos, fabs

enum fstyle { SOLID_FILL, X_FILL,      O_FILL,
			  LIGHT_FILL, MEDIUM_FILL, DARK_FILL };

enum color { cBLACK = 0,     cDARK_BLUE = 1,    cDARK_GREEN = 2, cDARK_CYAN = 3,
	         cDARK_RED = 4,  cDARK_MAGENTA = 5, cBROWN = 6,      cLIGHT_GRAY = 7,
	         cDARK_GRAY = 8, cBLUE = 9,         cGREEN = 10,     cCYAN = 11,
	         cRED = 12,      cMAGENTA = 13,     cYELLOW = 14,    cWHITE = 15 };

void init_graphics();
void set_color(color fg, color bg = cBLACK);
void set_cursor_pos(int x, int y);
void clear_screen();
void wait(int milliseconds);
void clear_line();
void draw_rectangle(int left, int top, int right, int bottom);
void draw_circle(int x, int y, int rad);
void draw_line(int x1, int y1, int x2, int y2);
void draw_pyramid(int x1, int y1, int height);
void set_fill_style(fstyle);
void end_graphics();

#endif // _INC_WCONSOLE