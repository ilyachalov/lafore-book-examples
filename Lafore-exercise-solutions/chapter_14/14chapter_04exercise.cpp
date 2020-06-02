// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 14chapter_04exercise.cpp
// Требуется написать функцию с именем swaps, меняющую местами два ее
// аргумента. После этого требуется переделать полученную функцию в шаблон.
// Требуется написать программу в функции main для проверки этого шаблона
// с несколькими базовыми числовыми типами (я выбрал int, double и wchar_t).

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <iostream>
using namespace std;

template <class T>           // шаблон
void swaps(T& arg1, T& arg2) // функции, меняющей местами значения ее аргументов
{
	T temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	int i1 = 23, i2 = 5;
	wcout << L"int: " << i1 << L' ' << i2 << L", ";
	swaps(i1, i2);
	wcout << L"меняем местами: " << i1 << L' ' << i2 << endl;

	double d1 = 3.521, d2 = -0.564;
	wcout << L"double: " << d1 << L' ' << d2 << L", ";
	swaps(d1, d2);
	wcout << L"меняем местами: " << d1 << L' ' << d2 << endl;

	wchar_t w1 = L'й', w2 = L'ы';
	wcout << L"wchar_t: " << w1 << L' ' << w2 << L", ";
	swaps(w1, w2);
	wcout << L"меняем местами: " << w1 << L' ' << w2 << endl;

	return 0;
}