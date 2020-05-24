// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// tempfind.cpp
// шаблон функции для поиска значения в массиве

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
using namespace std;

// функция возвращает индекс искомого в массиве значения или –1, если значение не найдено
template <class atype>
int find(atype* array, atype value, int size)
{
	for (int j = 0; j < size; j++)
		if (array[j] == value)
			return j;
	return -1;
}

// тестовые данные
char chrArr[]   = { 1, 3, 5, 9, 11, 13 };             // массив
char ch = 5;                                          // искомое значение
int intArr[]    = { 1, 3, 5, 9, 11, 13 };
int in = 6;
long lonArr[]   = { 1L, 3L, 5L, 9L, 11L, 13L };
long lo = 11L;
double dubArr[] = { 1.0, 3.0, 5.0, 9.0, 11.0, 13.0 };
double db = 4.0;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	wcout <<   L" 5 в chrArray: индекс = " << find(chrArr, ch, 6);
	wcout << L"\n 6 в intArray: индекс = " << find(intArr, in, 6);
	wcout << L"\n11 в lonArray: индекс = " << find(lonArr, lo, 6);
	wcout << L"\n 4 в dubArray: индекс = " << find(dubArr, db, 6);
	wcout << endl;
	
	return 0;
}