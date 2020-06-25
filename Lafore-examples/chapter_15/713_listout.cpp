// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// listout.cpp
// итератор и цикл for для вывода данных

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <iostream>
#include <list>         // для работы с контейнером list
// #include <algorithm> // не понадобился
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	int arr[] = { 2, 4, 6, 8 };
	list<int> theList;

	for (int k = 0; k < 4; k++)    // заполним список элементами массива
		theList.push_back(arr[k]);

	list<int>::iterator iter;      // итератор для списка элементов типа int

	for (iter = theList.begin(); iter != theList.end(); iter++)
		wcout << *iter << L' ';    // вывести на экран список

	wcout << endl;
	
	return 0;
}