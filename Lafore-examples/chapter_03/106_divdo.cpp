// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// divdo.cpp
// применение цикла do

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

	long dividend, divisor;
	wchar_t ch;
	do                 // начало цикла do
	{                  // действия
		wcout << L"Введите делимое: "; wcin >> dividend;
		wcout << L"Введите делитель: "; wcin >> divisor;
		wcout << L"Частное равно " << dividend / divisor;
		wcout << L", остаток равен " << dividend % divisor;
		wcout << L"\nЕще раз? (y/n): ";
		wcin >> ch;
	}
	while (ch != L'n'); // условие цикла

	return 0;
}