// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// circles.cpp
// круги в качестве объектов

#include "msoftcon.h" // для функций консольной графики

class circle // графический объект "круг"
{
protected:
	int xCo, yCo;     // координаты центра
	int radius;       // длина радиуса
	color fillcolor;  // цвет
	fstyle fillstyle; // стиль заполнения
public:
	void set(int x, int y, int r, color fc, fstyle fs) // установка атрибутов круга
	{
		xCo = x;
		yCo = y;
		radius = r;
		fillcolor = fc;
		fillstyle = fs;
	}
	void draw() // рисование круга
	{
		set_color(fillcolor);          // установка цвета
		set_fill_style(fillstyle);     // установка стиля заполнения
		draw_circle(xCo, yCo, radius); // рисование круга
	}
};

int main()
{
	init_graphics(); // инициализация графики
	
	circle c1; // объявление трех объектов класса circle, представляющих круги
	circle c2;
	circle c3;

	// задание параметров трех кругов
	c1.set(15,  7, 5, cBLUE,  X_FILL);
	c2.set(41, 12, 7, cRED,   O_FILL);
	c3.set(65, 18, 4, cGREEN, MEDIUM_FILL);
	
	// рисование трех кругов с заданными выше параметрами
	c1.draw();
	c2.draw();
	c3.draw();
	
	// установить курсор в нижний левый угол окна
	set_cursor_pos(1, 25);

	// возвратим первоначальный цвет текста в консоли
	end_graphics();

	return 0;
}