// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// nofri.cpp
// ограниченность перегруженной операции бинарного сложения (+)
// в случае, если не использовать дружественные функции

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

class Distance // длина в английской системе
{
private:
	int feet;     // футы (1 фут = 12 дюймов)
	float inches; // дюймы
public:
	// конструктор без аргументов
	Distance() : feet(0), inches(0.0)
		{ }
	// конструктор с одним аргументом (конвертирует float в Distance)
	Distance(float fltfeet)
	{
		feet = static_cast<int>(fltfeet); // футы — это целая часть fltfeet,
		inches = 12 * (fltfeet - feet);   // остальное — это дюймы
	}
	// конструктор с двумя аргументами
	Distance(int ft, float in) : feet(ft), inches(in)
		{ }
	void showdist() const // вывод полей на экран
		{ wcout << feet << L"\'-" << inches << L'\"'; }
	// сложение двух длин (перегрузка бинарной операции сложения)
	Distance operator+ (Distance) const; // прототип
};

// сложение двух длин (перегрузка бинарной операции сложения)
Distance Distance::operator+ (Distance d) const
{
	int f = feet + d.feet;       // складываем футы
	float i = inches + d.inches; // складываем дюймы
	if (i >= 12.0)               // если дюймов стало больше 12
	{
		i -= 12.0;               // то уменьшаем дюймы на 12
		f++;                     // и увеличиваем футы на 1
	}
	return Distance(f, i);       // создаем и возвращаем временную переменную
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	Distance d1 = 2.5;       // конструктор конвертирует
	Distance d2 = 1.25;      // вещественное число в объект класса Distance
	Distance d3;

	wcout << L"d1 = "; d1.showdist();
	wcout << L"\nd2 = "; d2.showdist();

	d3 = d1 + 10.0;          // distance + float: ТАК МОЖНО
	wcout << L"\nd3 = "; d3.showdist();

	// d3 = 10.0 + d1;       // float + Distance: ОШИБКА
	// wcout << L"\nd3 = "; d3.showdist();
	wcout << endl;

	return 0;
}