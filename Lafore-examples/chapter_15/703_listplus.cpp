// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// listplus.cpp
// демонстрирует методы двусвязного списка reverse, merge и unique

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
#include <list>      // для работы с контейнером list
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	int j;
	list<int> list1, list2;

	int arr1[] = { 40, 30, 20, 10 };
	int arr2[] = { 15, 20, 25, 30, 35 };

	for (j = 0; j < 4; j++)
		list1.push_back(arr1[j]);       // list1: 40, 30, 20, 10
	for (j = 0; j < 5; j++)
		list2.push_back(arr2[j]);       // list2: 15, 20, 25, 30, 35

	list1.reverse();                    // перевернуть list1: 10 20 30 40
	list1.merge(list2);                 // объединить list2 с list1
	list1.unique();                     // удалить повторяющиеся элементы 20 и 30

	int size = list1.size();
	while (!list1.empty())
	{
		wcout << list1.front() << L' '; // прочитать значение элемента из начала
		list1.pop_front();              // удалить элемент из начала
	}

	wcout << endl;
	
	return 0;
}