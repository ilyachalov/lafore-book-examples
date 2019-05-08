// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 05chapter_01exercise.cpp
// написать функцию circarea, вычисляющую площадь круга

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

float circarea(float r); // прототип функции

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	float rad; // радиус круга
	wcout << L"Введите радиус круга: ";
	wcin >> rad;
	wcout << L"Площадь круга равна " << circarea(rad) << endl;

	return 0;
}

// функция возвращает площадь круга с радиусом r
float circarea(float r)
{
	const float PI = 3.14159F; // число Пи
	return PI * r * r;
}