// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// sortemp.cpp
// сортирует массив типа double по убыванию,
// используя функциональный объект greater<>()

#include <io.h>       // для функции _setmode
#include <fcntl.h>    // для константы _O_U16TEXT
#include <iostream>
#include <algorithm>  // для алгоритма sort
// #include <functional> // для функционального объекта greater<> не понадобился
using namespace std;

// тестовый массив вещественных чисел
double fdata[] = { 19.2, 87.4, 33.6, 55.0, 11.5, 42.2 };

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	sort(fdata, fdata + 6, greater<double>()); // сортировка по убыванию,
	                                           // то есть сначала идут большие
	                                           // числа, затем — меньшие

	for (int j = 0; j < 6; j++)    // вывести отсортированный массив на экран
		wcout << fdata[j] << L' ';
	wcout << endl;
	
	return 0;
}