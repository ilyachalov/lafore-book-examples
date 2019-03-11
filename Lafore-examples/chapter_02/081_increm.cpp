// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// increm.cpp
// применение операции инкрементирования

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	int count = 10;
	wcout << L"count=" << count   << endl; // вывод числа 10
	wcout << L"count=" << ++count << endl; // вывод числа 11 (префиксная форма)
	wcout << L"count=" << count   << endl; // вывод числа 11
	wcout << L"count=" << count++ << endl; // вывод числа 11 (постфиксная форма)
	wcout << L"count=" << count   << endl; // вывод числа 12

	return 0;
}
