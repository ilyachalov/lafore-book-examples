// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// remaind.cpp
// применение операции остатка от деления

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	wcout <<  6 % 8 << endl  // 6
		  <<  7 % 8 << endl  // 7
		  <<  8 % 8 << endl  // 0
		  <<  9 % 8 << endl  // 1
		  << 10 % 8 << endl; // 2

	return 0;
}