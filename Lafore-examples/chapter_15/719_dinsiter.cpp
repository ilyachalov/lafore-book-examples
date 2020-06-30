// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// dinsiter.cpp
// демонстрирует применение итераторов вставки к двусторонним очередям

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <iostream>
#include <deque>        // для работы с контейнером deque
// #include <algorithm> // не понадобился
#include <iterator>     // для шаблонных функций front_inserter, inserter
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	int arr1[] = { 1, 3, 5, 7, 9 }; // массив для инициализации очереди d1
	int arr2[] = { 2, 4, 6 };       // массив для инициализации очереди d2
	deque<int> d1;
	deque<int> d2;

	for (int i = 0; i < 5; i++)     // перенесём массивы в очереди
		d1.push_back(arr1[i]);
	for (int j = 0; j < 3; j++)
		d2.push_back(arr2[j]);
	                                                             // копируем очередь d1:
	copy(d1.begin(), d1.end(), back_inserter(d2));               // — в конец очереди d2
	// copy(d1.begin(), d1.end(), front_inserter(d2));           // — в начало очереди d2
	// copy(d1.begin(), d1.end(), inserter(d2, d2.begin()));     // — в позицию 0 (начало) в d2
	// copy(d1.begin(), d1.end(), inserter(d2, d2.begin() + 2)); // — в позицию 2 в очереди d2

	wcout << L"d2: ";               // выведем на экран очередь d2
	for (int k = 0; k < d2.size(); k++)
		wcout << d2[k] << L' ';

	wcout << endl;
	
	return 0;
}