// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// copydeq.cpp
// демонстрирует обычное применение алгоритма copy к двусторонним очередям

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <iostream>
#include <deque>        // для работы с контейнером deque
// #include <algorithm> // не понадобился
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	int arr1[] = { 1, 3, 5, 7, 9 };
	int arr2[] = { 2, 4, 6, 8, 10 };
	deque<int> d1;
	deque<int> d2;

	for (int j = 0; j < 5; j++)             // перенесём массивы в очереди
	{
		d1.push_back(arr1[j]);
		d2.push_back(arr2[j]);
	}

	copy(d1.begin(), d1.end(), d2.begin()); // копируем очередь d1 в очередь d2

	for (int k = 0; k < d2.size(); k++)     // выведем на экран очередь d2
		wcout << d2[k] << L' ';

	wcout << endl;
	
	return 0;
}