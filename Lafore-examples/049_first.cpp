// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// first.cpp
// самый простой пример программы на языке C++

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	wcout << L"У каждой эпохи свой язык\n";
	return 0;
}