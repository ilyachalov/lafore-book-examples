// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// englarea.cpp
// использование вложенных структур

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

struct Distance      // длина в английской системе
{
	int feet;        // футы
	float inches;    // дюймы
};

struct Room          // размеры прямоугольной комнаты
{
	Distance length; // длина
	Distance width;  // ширина
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	Room dining; // переменная dining типа Room
	
	// задание параметров комнаты
	dining.length.feet = 13;
	dining.length.inches = 6.5;
	dining.width.feet = 10;
	dining.width.inches = 0.0;
	
	// преобразование длины и ширины в футы в вещественном формате
	float l = dining.length.feet + dining.length.inches / 12;
	float w = dining.width.feet + dining.width.inches / 12;

	// вычисление площади комнаты и вывод на экран
	wcout << L"Площадь комнаты равна " << l * w << L" квадратных футов\n";

	return 0;
}