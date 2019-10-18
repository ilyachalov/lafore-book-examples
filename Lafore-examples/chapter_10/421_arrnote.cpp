// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// arrnote.cpp
// обычный доступ к элементам массива

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	int intarray[5] = { 31, 54, 77, 52, 93 }; // массив из пяти целых чисел

	for (int j = 0; j < 5; j++)               // для каждого элемента массива
		wcout << intarray[j] << endl;         // выведем на экран его значение

	return 0;
}