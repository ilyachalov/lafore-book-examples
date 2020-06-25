// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// vectins.cpp
// демонстрирует применение методов вектора insert и erase

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
#include <vector>    // для работы с контейнером vector
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	int arr[] = { 100, 110, 120, 130 }; // массив типа int

	vector<int> v(arr, arr + 4);        // инициализировать вектор массивом

	wcout << L"Перед вставкой: ";
	for (int j = 0; j < v.size(); j++)  // вывести на экран все элементы
		wcout << v[j] << L' ';

	v.insert(v.begin() + 2, 115);       // вставить 115 в позицию 2

	wcout << L"\nПосле вставки:  ";
	for (int j = 0; j < v.size(); j++)  // вывести на экран все элементы
		wcout << v[j] << L' ';

	v.erase(v.begin() + 2);             // удалить элемент из позиции 2

	wcout << L"\nПосле удаления: ";
	for (int j = 0; j < v.size(); j++)  // вывести на экран все элементы
		wcout << v[j] << L' ';

	wcout << endl;
	
	return 0;
}