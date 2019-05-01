// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// overengl.cpp
// демонстрирует перегруженные функции (число аргументов одинаковое, типы разные)

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

struct Distance // длина в английской системе
{
	int feet;
	float inches;
};

void engldisp(Distance); // прототипы функций
void engldisp(float);

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	Distance d1; // длина типа Distance
	float d2;    // длина типа float
	
	// ввод значения d1
	wcout << L"Введите число футов: "; wcin >> d1.feet;
	wcout << L"Введите число дюймов: "; wcin >> d1.inches;
	// ввод значения d2
	wcout << L"Введите длину в дюймах: "; wcin >> d2;
	
	wcout << L"d1 = "; engldisp(d1);   // вывод значения d1
	wcout << L"\nd2 = "; engldisp(d2); // вывод значения d2
	wcout << endl;

	return 0;
}

// функция выводит на экран длину в футах и дюймах
void engldisp(Distance dd) // параметр dd типа Distance
{
	wcout << dd.feet << L"\'-" << dd.inches << L"\"";
}

// функция выводит на экран длину в футах и дюймах
void engldisp(float dd) // параметр dd типа float
{
	int feet = static_cast<int>(dd / 12);
	float inches = dd - feet * 12;
	wcout << feet << L"\'-" << inches << L"\"";
}