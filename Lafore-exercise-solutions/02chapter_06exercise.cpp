// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 02chapter_06exercise.cpp
// получить от пользователя число (сумму в американских долларах),
// вывести суммы, эквивалентные введенной пользователем, в других валютах,
// курс которых известен

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
#include <iomanip> // для манипуляторов fixed и setprecision
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	float sum = 0.0F, exRate = 1.0F; // денежная сумма и курс валюты

	wcout << L"Введите сумму в американских долларах: ";
	// при вводе суммы дробную часть необходимо отделять точкой
	// если отделить запятой, в sum попадет только целая часть
	wcin >> sum;
	// выводимые значения округляются до 2 знаков после запятой с помощью манипуляторов
	wcout << L"В американских долларах это " << fixed << setprecision(2) << sum / exRate << endl;
	exRate = 1.487F;
	wcout << L"В фунтах стерлингов это " << fixed << setprecision(2) << sum / exRate << endl;
	exRate = 0.172F;
	wcout << L"В франках это " << fixed << setprecision(2) << sum / exRate << endl;
	exRate = 0.584F;
	wcout << L"В немецких марках это " << fixed << setprecision(2) << sum / exRate << endl;
	exRate = 0.00955F;
	wcout << L"В японских йенах это " << fixed << setprecision(2) << sum / exRate << endl;

	return 0;
}