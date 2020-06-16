// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// count.cpp
// подсчитывает число объектов с заданным значением

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
// #include <algorithm> // для алгоритма count не понадобился
using namespace std;

int arr[] = { 33, 22, 33, 44, 33, 55, 66, 77 };

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	int n = count(arr, arr + 8, 33); // подсчитать, сколько раз встречается 33

	wcout << L"Число 33 встречается " << n << L" раз(а) в массиве." << endl;
	
	return 0;
}