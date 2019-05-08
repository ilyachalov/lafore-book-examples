// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 05chapter_04exercise.cpp
// написать функцию, возвращающую наибольшее из двух значений типа Distance,
// где Distance — структурная переменная, представляющая длину в английской системе

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

struct Distance // длина в английской системе
{
	int feet;     // футы
	float inches; // дюймы
};

Distance longest(Distance d1, Distance d2); // прототипы функций
void engldisp(Distance d);

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	Distance dis1, dis2; // для первой и второй длин
	
	// ввод двух длин в английской системе
	wcout << L"Введите число футов первой длины: "; wcin >> dis1.feet;
	wcout << L"Введите число дюймов первой длины: "; wcin >> dis1.inches;
	wcout << L"Введите число футов второй длины: "; wcin >> dis2.feet;
	wcout << L"Введите число дюймов второй длины: "; wcin >> dis2.inches;

	// выводим результат сравнения двух длин
	wcout << L"Наибольшая из этих двух длин: ";
	engldisp(longest(dis1, dis2));
	wcout << endl;

	return 0;
}

// функция возвращает наибольшую из двух длин
// (если длины равны, возвращается первое значение)
Distance longest(Distance d1, Distance d2)
{
	if (d1.feet > d2.feet)
		return d1;
	else if (d1.feet < d2.feet)
		return d2;
	else // d1.feet = d2.feet
	{
		if (d1.inches >= d2.inches)
			return d1;
		else // d1.inches < d2.inches
			return d2;
	}
}

// функция выводит поля структурной переменной типа Distance на экран
void engldisp(Distance d)
{
	wcout << d.feet << L"\'-" << d.inches << L"\"";
}