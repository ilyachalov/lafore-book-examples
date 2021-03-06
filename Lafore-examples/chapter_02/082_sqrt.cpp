﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// sqrt.cpp
// использование библиотечной функции sqrt()

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
// #include <cmath> // для sqrt() не потребовался
#include <iomanip> // для манипулятора setprecision()
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	double number, answer; // аргументы типа double для функции sqrt()
	wcout << L"Введите число: ";
	wcin >> number; // ввод числа
	answer = sqrt(number); // извлечение корня
	// вывод результата:
	// по умолчанию для вещественных чисел выводится 6 цифр всего (в сумме до запятой и после)
	// то есть, к примеру, квадратный корень из 1000 выведет 31.6228
	wcout << L"Квадратный корень равен " << answer << endl;
	// увеличиваем общее количество выводимых цифр в вещественном числе до 16
	// то есть, к примеру, квадратный корень из 1000 выведет 31.62277660168379
	wcout << L"Квадратный корень равен " << setprecision(16) << answer << endl;

	return 0;
}
