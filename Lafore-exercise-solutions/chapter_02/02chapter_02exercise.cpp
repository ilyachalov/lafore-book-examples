// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 02chapter_02exercise.cpp
// вывести заданную таблицу с выровненными столбцами

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
#include <iomanip> // для манипулятора setw
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	wcout << setw(4) << 1990 << setw(6) << 135 << endl
		  << setw(4) << 1991 << setw(6) << 7290 << endl
		  << setw(4) << 1992 << setw(6) << 11300 << endl
		  << setw(4) << 1993 << setw(6) << 16200 << endl;

	return 0;
}
