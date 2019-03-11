// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// while4.cpp
// возведение в четвертую степень целых чисел
// (при этом задается ограничение результата: в нем должно быть не более 4 цифр)

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
#include <iomanip> // для манипулятора setw
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	int pow = 1; // первое возводимое число равно 1
	int numb = 1; // 1 в 4-й степени равна 1
	while (pow < 10000) // цикл, пока в степени не более 4 цифр
	{
		wcout << setw(2) << numb;        // вывод числа
		wcout << setw(5) << pow << endl; // и его 4-й степени
		++numb;                          // инкремент текущего числа
		pow = numb * numb * numb * numb; // вычисление 4-й степени
	}
	wcout << endl;

	return 0;
}