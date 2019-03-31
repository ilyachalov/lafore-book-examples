// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// englstrc.cpp
// английская система мер, реализованная с помощью структуры

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

struct Distance // длина в английской системе
{
	int feet;
	float inches;
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	Distance d1, d3;            // определения двух переменных
	Distance d2 = { 11, 6.25 }; // определение с инициализацией

	// ввод полей переменной d1
	wcout << L"Введите число футов: "; wcin >> d1.feet;
	wcout << L"Введите число дюймов: "; wcin >> d1.inches;

	// сложение длин d1 и d2 и присвоение результата d3
	d3.inches = d1.inches + d2.inches; // сложение дюймов
	d3.feet = 0;                       // с возможным заемом
	if (d3.inches >= 12.0)             // если сумма больше или равна 12.0,
	{                                  // то уменьшаем
		d3.inches -= 12.0;             // число дюймов на 12.0 и
		d3.feet++;                     // увеличиваем число футов на 1
	}
	d3.feet += d1.feet + d2.feet;      // сложение футов
	
	// вывод всех длин на экран
	wcout << d1.feet << L"\'-" << d1.inches << L"\" + ";
	wcout << d2.feet << L"\'-" << d2.inches << L"\" = ";
	wcout << d3.feet << L"\'-" << d3.inches << L"\"\n";

	return 0;
}