// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// list.cpp
// демонстрирует методы двусвязного списка push_front, front, pop_front

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
#include <list>      // для работы с контейнером list
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	list<int> ilist;

	ilist.push_back(30);                // вставка элементов в конец
	ilist.push_back(40);
	ilist.push_front(20);               // вставка элементов в начало
	ilist.push_front(10);

	int size = ilist.size();            // количество элементов

	for (int j = 0; j < size; j++)
	{
		wcout << ilist.front() << L' '; // получить значение элемента из начала
		ilist.pop_front();              // удалить элемент из начала
	}

	wcout << endl;
	
	return 0;
}