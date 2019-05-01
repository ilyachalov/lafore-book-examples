// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// circstrc.cpp
// графические объекты типа "круг"

#include "msoftcon.h" // для графических функций

struct circle // графический объект "круг"
{
	int xCo, yCo;     // координаты центра
	int radius;       // длина радиуса
	color fillcolor;  // цвет
	fstyle fillstyle; // стиль заполнения
};

void circ_draw(circle c) // функция для рисования круга
{
	set_color(c.fillcolor);              // установка цвета
	set_fill_style(c.fillstyle);         // установка стиля заполнения
	draw_circle(c.xCo, c.yCo, c.radius); // рисование круга
}

int main()
{
	init_graphics(); // инициализация графики
	
	// задание параметров трех кругов
	circle c1 = { 15,  7, 5, cBLUE,  X_FILL };
	circle c2 = { 41, 12, 7, cRED,   O_FILL };
	circle c3 = { 65, 18, 4, cGREEN, MEDIUM_FILL };
	
	// рисование трех кругов с заданными выше параметрами
	circ_draw(c1);
	circ_draw(c2);
	circ_draw(c3);
	
	// установить курсор в нижний левый угол окна
	set_cursor_pos(1, 25);

	// возвратим первоначальный цвет текста в консоли
	end_graphics();

	return 0;
}