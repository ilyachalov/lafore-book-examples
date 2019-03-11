// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// fordemo.cpp
// демонстрирует работу простейшего цикла for

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	int j; // определение счетчика цикла
	for (j = 0; j < 15; j++) // счетчик меняется от 0 до 14
		wcout << j * j << L" "; // квадрат значения j выводится на экран
	wcout << endl;

	return 0;
}