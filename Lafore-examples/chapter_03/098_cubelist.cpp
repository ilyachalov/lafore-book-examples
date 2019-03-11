// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// cubelist.cpp
// подсчет кубов целых чисел от 1 до 10

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
#include <iomanip> // для манипулятора setw
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	int numb; // счетчик цикла
	for (numb = 1; numb <= 10; numb++) // цикл от 1 до 10
	{
		wcout << setw(4) << numb; // вывод первого столбца
		int cube = numb * numb * numb; // вычисление куба
		wcout << setw(6) << cube << endl; // вывод второго столбца
	}

	return 0;
}