// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// multshap.cpp
// геометрические фигуры

#include "msoftcon.h" // для функций консольной графики

class shape // базовый класс (реализует общую для всех фигур часть)
{
protected:
	int xCo, yCo;     // координаты фигуры
	color fillcolor;  // цвет
	fstyle fillstyle; // стиль закрашивания
public:
	// конструктор без аргументов
	shape() : xCo(0), yCo(0), fillcolor(cWHITE), fillstyle(SOLID_FILL)
		{ }
	// конструктор с четырьмя аргументами
	shape(int x, int y, color fc, fstyle fs) : xCo(x), yCo(y), fillcolor(fc), fillstyle(fs)
		{ }
	void draw() const // метод установки цвета и стиля закрашивания фигуры
	{
		set_color(fillcolor);
		set_fill_style(fillstyle);
	}
};

class circle : public shape // производный класс (реализует фигуру «круг»)
{
private:
	int radius; // радиус круга,
	// а xCo и yCo из базового класса будут координатами центра круга
public:
	// конструктор без аргументов
	circle() : shape()
		{ }
	// конструктор с пятью аргументами
	circle(int x, int y, int r, color fc, fstyle fs) : shape(x, y, fc, fs), radius(r)
		{ }
	void draw() const // метод рисования круга
	{
		shape::draw();
		draw_circle(xCo, yCo, radius);
	}
};

class rect : public shape // производный класс (реализует фигуру «прямоугольник»)
{
private:
	int width, height; // ширина и высота прямоугольника,
	// а xCo и yCo из базового класса будут координатами верхнего левого угла прямоугольника
public:
	// конструктор без аргументов
	rect() : shape(), height(0), width(0)
		{ }
	// конструктор с шестью аргументами
	rect(int x, int y, int h, int w, color fc, fstyle fs) : shape(x, y, fc, fs), height(h), width(w)
		{ }
	void draw() const // метод рисования прямоугольника
	{
		shape::draw();
		draw_rectangle(xCo, yCo, xCo + width, yCo + height);
		// нарисуем диагональ из левого верхнего угла прямоугольника в его правый нижний угол
		set_color(cWHITE);                              // установим цвет диагонали
		draw_line(xCo, yCo, xCo + width, yCo + height); // рисуем линию диагонали
	}
};

class tria : public shape // производный класс (реализует фигуру «треугольник»)
{
private:
	int height; // высота треугольника,
	// а xCo и yCo из базового класса будут координатами вершины треугольника

	// Отметим, что этот объект реализует не любой возможный треугольник, а только
	// равнобедреный, основание которого является горизонтальной линией. Чтобы
	// нарисовать такой треугольник, достаточно знать координаты его вершины и
	// его высоту (расстояние от вершины до основания).

public:
	// конструктор без аргументов
	tria() : shape(), height(0)
		{ }
	// конструктор с пятью аргументами
	tria(int x, int y, int h, color fc, fstyle fs) : shape(x, y, fc, fs), height(h)
		{ }
	void draw() const // метод рисования треугольника
	{
		shape::draw();
		draw_pyramid(xCo, yCo, height);
	}
};

int main()
{
	init_graphics(); // инициализация графики

	circle cir(40, 12, 5, cBLUE, X_FILL);      // создаем круг
	rect rec(12, 7, 10, 15, cRED, SOLID_FILL); // создаем прямоугольник
	tria tri(60, 7, 11, cGREEN, MEDIUM_FILL);  // создаем треугольник

	cir.draw(); // рисуем созданные фигуры
	rec.draw();
	tri.draw();

	// установить курсор в нижний левый угол окна
	set_cursor_pos(1, 25);

	// возвратим первоначальный цвет текста в консоли
	end_graphics();

	return 0;
}