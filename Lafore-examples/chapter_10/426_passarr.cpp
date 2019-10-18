// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// passarr.cpp
// передача массива в функцию по указателю

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

const int MAX = 5; // количество элементов в массиве

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	void centimize(double*); // прототип функции

	double varray[MAX] = { 10.0, 43.1, 95.9, 58.7, 87.3 };
	
	centimize(varray);       // переведем все элементы массива в сантиметры

	// покажем, что у нас получилось
	for (int j = 0; j < MAX; j++)
		wcout << L"varray[" << j << L"] = " << varray[j] << L" см" << endl;

	return 0;
}

// функция для перевода дюймов в сантиметры
void centimize(double* ptrd)
{
	for (int j = 0; j < MAX; j++)
		*ptrd++ *= 2.54;     // ptrd указывает на элементы массива varray
}