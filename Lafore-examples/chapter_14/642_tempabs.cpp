// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// tempabs.cpp
// шаблон функции вычисления модуля числа

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
using namespace std;

template <class T>   // шаблон функции
T abs(T n)
{
	return (n < 0) ? -n : n;
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	int int1 = 5;
	int int2 = -6;
	long lon1 = 70000L;
	long lon2 = -80000L;
	double dub1 = 9.95;
	double dub2 = -10.15;
	
	// вызовы функций по шаблону с аргументами разных типов

	wcout << L"abs(" << int1 << L") = " << abs(int1); // abs(int)
	wcout << L"\nabs(" << int2 << L") = " << abs(int2); // abs(int)
	wcout << L"\nabs(" << lon1 << L") = " << abs(lon1); // abs(long)
	wcout << L"\nabs(" << lon2 << L") = " << abs(lon2); // abs(long)
	wcout << L"\nabs(" << dub1 << L") = " << abs(dub1); // abs(double)
	wcout << L"\nabs(" << dub2 << L") = " << abs(dub2); // abs(double)
	wcout << endl;
	
	return 0;
}