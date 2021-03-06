﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// endono.cpp
// применение цикла while

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	int n = 99;    // n не должна быть равна 0 перед началом цикла
	while (n != 0) // цикл, пока значение n не равно 0
		wcin >> n;  // считывание n с клавиатуры
	wcout << endl;

	return 0;
}