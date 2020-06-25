// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// itercopy.cpp
// использует итераторы для алгоритма copy

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <iostream>
#include <vector>       // для работы с контейнером vector
// #include <algorithm> // не понадобился
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);
	
	int beginRange, endRange;
	int arr[] = { 11, 13, 15, 17, 19, 21, 23, 25, 27, 29 };
	vector<int> v1(arr, arr + 10); // инициализированный вектор
	vector<int> v2(10);            // неинициализированный вектор

	wcout << L"Введите диапазон копирования (пример: 2 5): ";
	wcin >> beginRange >> endRange;

	vector<int>::iterator iter1 = v1.begin() + beginRange;
	vector<int>::iterator iter2 = v1.begin() + endRange;
	vector<int>::iterator iter3;
	                               // копировать диапазон из v1 в v2
	iter3 = copy(iter1, iter2, v2.begin());
	                               // (iter3 -> последний скопированный элемент
	                               // во втором векторе)

	iter1 = v2.begin();            // пройдем в цикле по диапазону во 2-м векторе
	while (iter1 != iter3)         // вывести на экран элементы из диапазона
		                           // во втором векторе
		wcout << *iter1++ << L' ';

	wcout << endl;
	
	return 0;
}