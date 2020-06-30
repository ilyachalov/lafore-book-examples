// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// iterev.cpp
// демонстрирует обратный итератор

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
#include <list>      // для работы с контейнером list
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	int arr[] = { 2, 4, 6, 8, 10 };    // массив типа int
	list<int> theList;

	for (int j = 0; j < 5; j++)        // перенесём массив в список
		theList.push_back(arr[j]);

	list<int>::reverse_iterator revit; // обратный итератор

	revit = theList.rbegin();          // пройдем в цикле в обратном порядке
	while (revit != theList.rend())    // по списку,
		wcout << *revit++ << L' ';     // выводя на экран значения его элементов

	wcout << endl;
	
	return 0;
}