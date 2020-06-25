// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// iterfind_vect.cpp
// алгоритм find возвращает итератор на элемент в векторе

#include <io.h>         // для функции _setmode
#include <fcntl.h>      // для константы _O_U16TEXT
#include <iostream>
// #include <algorithm> // не понадобился
#include <vector>       // для работы с контейнером vector
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	vector<int> theVect(5);     // пустой вектор для хранения 5 значений типа int
	vector<int>::iterator iter; // итератор
	int data = 0;
	                          // заполним вектор данными
	for (iter = theVect.begin(); iter != theVect.end(); iter++)
		*iter = data += 2;    // 2, 4, 6, 8, 10
	                          // ищем число 8
	iter = find(theVect.begin(), theVect.end(), 8);
	if (iter != theVect.end())
		wcout << L"Число 8 найдено в позиции " << (iter - theVect.begin());
	else
		wcout << L"Число 8 не найдено";

	wcout << endl;
	
	return 0;
}