// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// engldisp.cpp
// передача структурных переменных в функцию

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

struct Distance // длина в английской системе
{
	int feet;
	float inches;
};

void engldisp(Distance); // объявление функции

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	Distance d1, d2; // определение двух длин
	
	// ввод значений полей d1
	wcout << L"Введите число футов: "; wcin >> d1.feet;
	wcout << L"Введите число дюймов: "; wcin >> d1.inches;
	// ввод значений полей d2
	wcout << L"Введите число футов: "; wcin >> d2.feet;
	wcout << L"Введите число дюймов: "; wcin >> d2.inches;
	
	wcout << L"d1 = ";
	engldisp(d1); // вывод значения d1
	wcout << L"\nd2 = ";
	engldisp(d2); // вывод значения d2
	wcout << endl;

	return 0;
}

// функция engldisp(), отображающая значения
// полей структурной переменной типа Distance
void engldisp(Distance dd) // параметр dd типа Distance
{
	wcout << dd.feet << L"\'-" << dd.inches << L"\"";
}