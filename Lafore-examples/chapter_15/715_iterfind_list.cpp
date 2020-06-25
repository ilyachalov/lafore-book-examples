// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// iterfind_list.cpp
// алгоритм find возвращает итератор на элемент в списке

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <iostream>
// #include <algorithm> // не понадобился
#include <list>         // для работы с контейнером list
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	list<int> theList(5);     // пустой список для хранения 5 значений типа int
	list<int>::iterator iter; // итератор
	int data = 0;
	                          // заполним список данными
	for (iter = theList.begin(); iter != theList.end(); iter++)
		*iter = data += 2;    // 2, 4, 6, 8, 10
	                          // ищем число 8
	iter = find(theList.begin(), theList.end(), 8);
	if (iter != theList.end())
		wcout << L"Найдено число 8.\n";
	else
		wcout << L"Число 8 не найдено.\n";
	
	return 0;
}