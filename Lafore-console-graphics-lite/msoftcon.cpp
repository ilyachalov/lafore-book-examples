// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// msoftcon.cpp
// Функции консольной графики от Роберта Лафоре
// (в них используются консольные функции Windows)

#include "msoftcon.h"

HANDLE hConsole;   // дескриптор консоли
wchar_t fill_char; // символ заполнения
CONSOLE_SCREEN_BUFFER_INFO info; // информация о настройках консоли

//---------------------------------------------------------
void init_graphics()
{
	COORD console_size = { 80, 25 };
	// открыть канал ввода/вывода на консоль
	hConsole = CreateFile("CONOUT$", GENERIC_WRITE | GENERIC_READ,
		                  FILE_SHARE_READ | FILE_SHARE_WRITE,
		                  0L, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0L);
	// установить размер экрана 80 x 25
	SetConsoleScreenBufferSize(hConsole, console_size);
	
	// текст белым по черному
	// (закомментировал, так как у консоли есть цвета по умолчанию)
	// SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
	
	// запомним первоначальные настройки консоли
	GetConsoleScreenBufferInfo(hConsole, &info);

	fill_char = L'\x2588'; // заполнение по умолчанию
	clear_screen();
}

//---------------------------------------------------------
// Возможные значения цветов (см. перечисление color в файле "msoftcon.h"):
// 0 Черный           8 Темно-серый
// 1 Темно-синий      9 Синий
// 2 Темно-зеленый   10 Зеленый
// 3 Темно-голубой   11 Голубой
// 4 Темно-красный   12 Красный
// 5 Темно-пурпурный 13 Пурпурный
// 6 Коричневый      14 Желтый
// 7 Светло-серый    15 Белый
void set_color(color foreground, color background)
{
	SetConsoleTextAttribute(hConsole, (WORD)((background << 4) | foreground));
}

//---------------------------------------------------------
// Изменил формулы так, чтобы координаты курсора были относительными,
// так как не всегда левый верхний угол имеет координаты (0, 0).
// Например, если программу запустить несколько раз из командной строки,
// при втором запуске, к примеру, координата Y должна быть больше
// на высоту первого результата работы программы и так далее.
void set_cursor_pos(int x, int y)
{
	COORD cursor_pos;                               // Начало в верхнем левом углу
	cursor_pos.X = info.dwCursorPosition.X + x - 1; // Windows начинает с (0, 0)
	cursor_pos.Y = info.dwCursorPosition.Y + y - 1; // мы начнем с (1, 1)
	SetConsoleCursorPosition(hConsole, cursor_pos);
}

//---------------------------------------------------------
void clear_screen()
{
	set_cursor_pos(1, 1);
	for (int j = 0; j < 25; j++)
		_putwch(L'\n');
	set_cursor_pos(1, 1);
}

//---------------------------------------------------------
void wait(int milliseconds)
{
	Sleep(milliseconds);
}

//---------------------------------------------------------
void clear_line() // очистка до конца строки (80 пробелов)
{
	//........1234567890123456789012345678901234567890
	//........0........1.........2.........3.........4
	_cputws(L"                                        ");
	_cputws(L"                                        ");
}

//---------------------------------------------------------
void draw_rectangle(int left, int top, int right, int bottom)
{
	wchar_t temp[80];
	int width = right - left + 1;

	for (int j = 0; j < width; j++) // строка прямоугольника
		temp[j] = fill_char;
	temp[width] = 0;                // null (отметка окончания строки)

	for (int y = top; y <= bottom; y++) // выводом множества строк
	{                                   // формируем прямоугольник
		set_cursor_pos(left, y);
		_cputws(temp);
	}
}

//---------------------------------------------------------
void draw_circle(int xC, int yC, int radius)
{
	double theta, increment, xF, pi = 3.14159;
	int x, xN, yN;

	increment = 0.8 / static_cast<double>(radius);
	for (theta = 0; theta <= pi / 2; theta += increment) // 1/4 круга
	{
		xF = radius * cos(theta);
		xN = static_cast<int>(xF * 2 / 1); // пиксели не квадратные :-(
		yN = static_cast<int>(radius * sin(theta) + 0.5);
		x = xC - xN;
		while (x <= xC + xN) // заполнить две горизонтальные линии
		{                    // по одной на каждую половинку круга
			set_cursor_pos(x, yC - yN); _putwch(fill_char);   // верх
			set_cursor_pos(x++, yC + yN); _putwch(fill_char); // низ
		}
	}
}

//---------------------------------------------------------
void draw_line(int x1, int y1, int x2, int y2)
{
	int w, z, t, w1, w2, z1, z2;
	double xDelta = x1 - x2, yDelta = y1 - y2, slope;
	bool isMoreHoriz;
	
	if (fabs(xDelta) > fabs(yDelta)) // ближе к горизонтальной линии
	{
		isMoreHoriz = true;
		slope = yDelta / xDelta;
		w1 = x1; z1 = y1; w2 = x2, z2 = y2; // w=x, z=y
	}
	else                             // ближе к вертикальной линии
	{
		isMoreHoriz = false;
		slope = xDelta / yDelta;
		w1 = y1; z1 = x1; w2 = y2, z2 = x2; // w=y, z=x
	}

	if (w1 > w2)                 // если за w
	{
		t = w1; w1 = w2; w2 = t; // поменять местами (w1,z1)
		t = z1; z1 = z2; z2 = t; //                и (w2,z2)
	}

	for (w = w1; w <= w2; w++)
	{
		z = static_cast<int>(z1 + slope * (w - w1));
		if (!(w == 80 && z == 25)) // убрать прокрутку на 80,25
		{
			if (isMoreHoriz)
				set_cursor_pos(w, z);
			else
				set_cursor_pos(z, w);
			_putwch(fill_char);
		}
	}
}

//---------------------------------------------------------
void draw_pyramid(int x1, int y1, int height)
{
	int x, y;
	for (y = y1; y < y1 + height; y++)
	{
		int incr = y - y1;
		for (x = x1 - incr; x <= x1 + incr; x++)
		{
			set_cursor_pos(x, y);
			_putwch(fill_char);
		}
	}
}

//---------------------------------------------------------
void set_fill_style(fstyle fs)
{
	switch (fs)
	{
	case SOLID_FILL:  fill_char = L'\x2588'; break;
	case DARK_FILL:   fill_char = L'\x2591'; break;
	case MEDIUM_FILL: fill_char = L'\x2592'; break;
	case LIGHT_FILL:  fill_char = L'\x2593'; break;
	case X_FILL:      fill_char = L'X'; break;
	case O_FILL:      fill_char = L'O'; break;
	}
}

//---------------------------------------------------------
void end_graphics()
{
	// вернем первоначальные настройки цветов
	SetConsoleTextAttribute(hConsole, info.wAttributes);
}