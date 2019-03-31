// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// dayenum.cpp
// применение перечислений

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

// объявление перечисляемого типа
enum days_of_week { Sun, Mon, Tue, Wed, Thu, Fri, Sat };

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	days_of_week day1, day2; // определения переменных, хранящих дни недели
	day1 = Mon;              // инициализация переменных
	day2 = Thu;
	int diff = day2 - day1;  // арифметическая операция
	wcout << L"Разница в днях: " << diff << endl;
	if (day1 < day2)         // сравнение
		wcout << L"day1 наступит раньше, чем day2\n";

	return 0;
}