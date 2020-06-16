// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// sort.cpp
// сортирует массив целых чисел

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
#include <algorithm> // для алгоритма sort
using namespace std;

// тестовый массив целых чисел
int arr[] = { 45, 2, 22, -17, 0, -30, 25, 55 };

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	sort(arr, arr + 8);          // сортировка

	for (int j = 0; j < 8; j++)  // вывести отсортированный массив на экран
		wcout << arr[j] << L' ';
	wcout << endl;
	
	return 0;
}