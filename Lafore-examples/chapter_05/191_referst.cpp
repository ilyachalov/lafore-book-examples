// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// referst.cpp
// передача структурной переменной по ссылке

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

struct Distance // длина в английской системе
{
	int feet;
	float inches;
};

void scale(Distance&, float); // прототипы функций
void engldisp(Distance);

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	Distance d1 = { 12, 6.5 }; // инициализация d1 и d2
	Distance d2 = { 10, 5.5 };

	wcout << L"d1 = "; engldisp(d1); // вывод исходных значений d1 и d2
	wcout << L"\nd2 = "; engldisp(d2);

	scale(d1, 0.5); // масштабирование d1 и d2
	scale(d2, 0.25);
	
	wcout << L"\nd1 = "; engldisp(d1); // вывод новых значений d1 и d2
	wcout << L"\nd2 = "; engldisp(d2);
	wcout << endl;

	return 0;
}

// функция scale() выполняет масштабирование значения типа Distance
void scale(Distance& dd, float factor)
{
	float inches = (dd.feet * 12 + dd.inches) * factor; // перевод футов в дюймы и ум-
	dd.feet = static_cast<int>(inches / 12);            // ножение на коэффициент
	dd.inches = inches - dd.feet * 12;
}

// функция engldisp()
// отображает значение типа Distance на экране
void engldisp(Distance dd) // параметр dd типа Distance
{
	wcout << dd.feet << L"\'-" << dd.inches << L"\"";
}