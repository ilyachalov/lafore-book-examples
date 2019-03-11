// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// if2.cpp
// использование нескольких операторов в теле ветвления if

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

	int x;
	wcout << L"Введите число: ";
	wcin >> x;
	if (x > 100)
	{
		wcout << L"Число " << x;
		wcout << L" больше, чем 100\n";
	}

	return 0;
}