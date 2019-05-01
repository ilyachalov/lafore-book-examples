// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// vararg.cpp
// передача переменных в функцию в качестве аргументов

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

void repchar(wchar_t, int); // объявление функции

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	wchar_t chin;
	int nin;
	wcout << L"Введите символ: ";
	wcin >> chin;
	wcout << L"Введите число повторений символа: ";
	wcin >> nin;
	repchar(chin, nin);

	return 0;
}

// определение функции repchar()
void repchar(wchar_t ch, int n) // заголовок функции
{
	for (int j = 0; j < n; j++) // тело функции
		wcout << ch;
	wcout << endl;
}