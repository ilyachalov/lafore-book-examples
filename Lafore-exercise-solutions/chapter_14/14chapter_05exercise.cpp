// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 14chapter_05exercise.cpp
// Требуется написать функцию с именем amax, которая возвращает значение
// самого большого элемента в массиве. Аргументами этой функции должны быть
// адрес массива и его размер. После этого требуется переделать эту функцию
// в шаблон так, чтобы она могла работать с массивом любого базового числового
// типа. В функции main требуется написать программу для тестирования этого
// шаблона с массивами различных числовых базовых типов (я выбрал int, double
// и wchar_t).

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <iostream>
using namespace std;

template <class T>
T amax(T* array, int size)
{
	T temp = array[0];
	for (int i = 1; i < size; i++)
		if (temp < array[i])
			temp = array[i];
	return temp;
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	int ari[] = { 98, 54, -7, 65, 0, 3 };
	wcout << amax(ari, 6) << endl;

	double ard[] = { 0.562, -87.42, 786.43, 3.21 };
	wcout << amax(ard, 4) << endl;

	wchar_t arw[] = L"Папа у Васи силён в математике!";
	wcout << amax(arw, 32) << endl;

	return 0;
}