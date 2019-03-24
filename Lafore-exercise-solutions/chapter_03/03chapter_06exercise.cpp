// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 03chapter_06exercise.cpp
// Подсчет факториала числа с помощью цикла for.
// Вставить программу вычисления факториала в цикл, условие выхода — ввод пользователем 0.

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

	unsigned int numb;
	unsigned long fact; // тип long для результата
	
	do {
		fact = 1;
		wcout << L"Введите целое число: ";
		wcin >> numb; // ввод числа
		for (int j = numb; j > 0; j--) // умножение fact на
			fact *= j;                 // numb, numb-1, ..., 2, 1
		wcout << L"Факториал числа равен " << fact << endl;
	} while (numb != 0);

	return 0;
}