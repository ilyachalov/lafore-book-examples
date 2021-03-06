﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// twostr.cpp
// определение строковой константы через массив и через указатель

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	wchar_t str1[] = L"Определение через массив";
	const wchar_t* str2 = L"Определение через указатель";

	// При определении строки str2 служебное слово const относится не к
	// переменной str2, а к значению, на которое указывает указатель str2.
	// То есть str2 — указатель-переменная, указывающая на константное
	// значение (в данном случае — на строковую константу).

	wcout << str1 << endl; // выведем на экран наши строки
	wcout << str2 << endl;

	// str1++; // так делать нельзя, так как str1 — указатель-константа
	str2++;    // а так можно, так как str2 — указатель-переменная

	wcout << str2 << endl; // теперь str2 начинается со второй буквы
	                       // первоначальной строки

	return 0;
}