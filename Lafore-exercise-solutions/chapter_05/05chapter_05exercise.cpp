// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 05chapter_05exercise.cpp
// Написать функцию hms_to_secs с тремя аргументами (часы, минуты, секунды) типа int.
// Она должна возвращать эквивалент переданного ей времени в секундах (типа long).

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

long hms_to_secs(int h, int m, int s); // прототип функции

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	int hr, min, sec; // для часов, минут и секунд
	wchar_t colon;    // для двоеточия
	wchar_t ch;       // для ответа на вопрос о продолжении работы программы

	do {
		wcout << L"Введите время в часах, минутах и секундах (через двоеточие): ";
		wcin >> hr >> colon >> min >> colon >> sec;
		wcout << L"Эквивалент в секундах: " << hms_to_secs(hr, min, sec) << endl;
		wcout << L"Продолжить (д/н)? "; wcin >> ch;
	} while (ch != L'н');

	return 0;
}

// функция получает время в часах, минутах, секундах и
// возвращает эквивалент в секундах
long hms_to_secs(int h, int m, int s)
{
	return (h * 3600 + m * 60 + s);
}