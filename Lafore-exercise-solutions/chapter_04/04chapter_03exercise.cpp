// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 04chapter_03exercise.cpp
// Программа для расчета объема помещения с использованием вложенных структур.
// Размеры помещения указываются в футах и дюймах (1 фут = 12 дюймов).

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

struct Distance // длина в английской системе
{
	int feet;     // футы
	float inches; // дюймы
};

struct Volume   // размер помещения
{
	Distance length; // длина
	Distance width;  // ширина
	Distance height; // высота
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	Volume room; // создание структурной переменной типа Volume
	float vol; // объем помещения

	// инициализация структурной переменной room
	wcout << L"Введите размеры помещения (в футах и дюймах через пробел)\n";
	wcout << L"Длина: "; wcin >> room.length.feet >> room.length.inches;
	wcout << L"Ширина: "; wcin >> room.width.feet >> room.width.inches;
	wcout << L"Высота: "; wcin >> room.height.feet >> room.height.inches;

	// вычисление объема помещения в кубических футах
	vol = (room.length.feet + room.length.inches / 12)
	      * (room.width.feet + room.width.inches / 12)
	      * (room.height.feet + room.height.inches / 12);

	// вывод результата на экран
	wcout << L"Объем помещения в кубических футах: " << vol << endl;

	return 0;
}