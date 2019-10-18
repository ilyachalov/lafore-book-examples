// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ptrinc.cpp
// доступ к элементам массива через указатель с помощью операции инкремента

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	int intarray[5] = { 31, 54, 77, 52, 93 }; // массив из пяти целых чисел
	int* ptrint;                              // указатель на int
	ptrint = intarray;                        // пусть он указывает на наш массив

	for (int j = 0; j < 5; j++)               // для каждого элемента массива
		wcout << *(ptrint++) << endl;         // выведем на экран его значение

	return 0;
}