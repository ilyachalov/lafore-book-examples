// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// find.cpp
// ищет первый объект с заданным значением

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
// #include <algorithm> // для алгоритма find не понадобился
using namespace std;

int arr[] = { 11, 22, 33, 44, 55, 66, 77, 88 };

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	int* ptr;

	ptr = find(arr, arr + 8, 33); // найти первое вхождение 33
	
	wcout << L"Первый объект со значением 33 найден в позиции "
		<< (ptr - arr) << endl;
	
	return 0;
}