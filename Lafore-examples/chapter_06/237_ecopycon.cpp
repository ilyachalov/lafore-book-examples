// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ecopycon.cpp
// инициализация объектов с помощью копирующего конструктора

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

class Distance // длина в английской системе
{
private:
	int feet;     // футы
	float inches; // дюймы
public:
	// конструктор без аргументов
	Distance() : feet(0), inches(0.0)
		{ }
	// конструктора с одним аргументом нет!
	// конструктор с двумя аргументами
	Distance(int ft, float in) : feet(ft), inches(in)
		{ }
	void getdist() // ввод полей с клавиатуры
	{
		wcout << L"Введите число футов: "; wcin >> feet;
		wcout << L"Введите число дюймов: "; wcin >> inches;
	}
	void showdist() // вывод полей на экран
		{ wcout << feet << L"\'-" << inches << L'\"'; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	Distance dist1(11, 6.25); // конструктор с двумя аргументами
	Distance dist2(dist1);    // конструктор с одним аргументом
	Distance dist3 = dist1;

	// вывод всех длин на экран
	wcout << L"dist1 = "; dist1.showdist();
	wcout << L"\ndist2 = "; dist2.showdist();
	wcout << L"\ndist3 = "; dist3.showdist();
	wcout << endl;

	return 0;
}