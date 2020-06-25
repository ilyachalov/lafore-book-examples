// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// for_each.cpp
// использует алгоритм for_each для вывода на экран элементов массива,
// содержащих значения в дюймах, переведенных в сантиметры

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
#include <algorithm> // для алгоритма for_each
using namespace std;

void in_to_cm(double); // объявление функции

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	// тестовый массив значений в дюймах
	double inches[] = { 3.5, 6.2, 1.0, 12.75, 4.33 };
	
	// вывод на экран значений тестового массива, переведенных в сантиметры
	for_each(inches, inches + 5, in_to_cm);

	wcout << endl;
	
	return 0;
}

void in_to_cm(double in) // перевод в сантиметры и вывод на экран
{
	wcout << (in * 2.54) << L' ';
}