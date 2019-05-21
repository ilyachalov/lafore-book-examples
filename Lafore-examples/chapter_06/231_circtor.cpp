// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// circtor.cpp
// графические объекты "круг" и конструкторы

#include "msoftcon.h" // для функций консольной графики

class circle // графический объект "круг"
{
protected:
	int xCo, yCo;     // координаты центра
	int radius;       // длина радиуса
	color fillcolor;  // цвет
	fstyle fillstyle; // стиль заполнения
public:
	// конструктор
	circle(int x, int y, int r, color fc, fstyle fs) :
		xCo(x), yCo(y), radius(r), fillcolor(fc), fillstyle(fs)
	{ }
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
	
	// создание кругов с одновременным заданием их параметров
	circle c1(15,  7, 5, cBLUE,  X_FILL);
	circle c2(41, 12, 7, cRED,   O_FILL);
	circle c3(65, 18, 4, cGREEN, MEDIUM_FILL);
	
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