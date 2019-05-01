// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// convert.cpp
// демонстрирует механизм возврата значения функцией

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

float lbstokg(float); // прототип функции

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	float lbs, kgs;
	wcout << L"Введите вес в фунтах: ";
	wcin >> lbs;
	kgs = lbstokg(lbs);
	wcout << L"Вес в килограммах равен " << kgs << endl;

	return 0;
}

// функция lbstokg()
// переводит фунты в килограммы
float lbstokg(float pounds)
{
	float kilograms = 0.453592 * pounds;
	return kilograms;
}