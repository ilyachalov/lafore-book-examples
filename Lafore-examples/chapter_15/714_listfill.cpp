// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// listfill.cpp
// использует итератор для заполнения списка данными

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
#include <list>      // для работы с контейнером list
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	list<int> iList(5);     // пустой список для хранения 5 значений типа int
	list<int>::iterator it; // итератор
	int data = 0;
	                        // заполним список данными
	for (it = iList.begin(); it != iList.end(); it++)
		*it = data += 2;
	                        // выведем список на экран
	for (it = iList.begin(); it != iList.end(); it++)
		wcout << *it << L' ';

	wcout << endl;
	
	return 0;
}