// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// overload.cpp
// перегрузка функций

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

void repchar();             // прототипы функций
void repchar(wchar_t);
void repchar(wchar_t, int);

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	repchar();
	repchar(L'=');
	repchar(L'+', 30);

	return 0;
}

// функция выводит на экран 45 символов '*'
void repchar()
{
	for (int j = 0; j < 45; j++) // цикл, выполняющийся 45 раз
		wcout << L'*';           // вывод символа '*'
	wcout << endl;
}

// функция выводит на экран 45 заданных символов
void repchar(wchar_t ch)
{
	for (int j = 0; j < 45; j++) // цикл, выполняющийся 45 раз
		wcout << ch;             // вывод заданного символа
	wcout << endl;
}

// функция выводит на экран заданный символ заданное число раз
void repchar(wchar_t ch, int n)
{
	for (int j = 0; j < n; j++) // цикл, выполняющийся n раз
		wcout << ch;            // вывод заданного символа
	wcout << endl;
}