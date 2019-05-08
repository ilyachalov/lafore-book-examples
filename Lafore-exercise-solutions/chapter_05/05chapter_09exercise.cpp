// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 05chapter_09exercise.cpp
// переписать функцию swap из упражнения 8, обменивающую значениями два своих аргумента,
// при этом изменяться должны значения переменных из вызывающей программы,
// только теперь эти значения должны быть структурного типа time из упражнения 6

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

struct time // время
{
	int hours;   // часы
	int minutes; // минуты
	int seconds; // секунды
};

void swap(time& n1, time& n2); // прототип функции

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	time t1, t2;   // для двух отрезков времени
	wchar_t colon; // для двоеточия
	
	// получаем два отрезка времени от пользователя с клавиатуры
	wcout << L"Введите время в часах, минутах и секундах (через двоеточие): ";
	wcin >> t1.hours >> colon >> t1.minutes >> colon >> t1.seconds;
	wcout << L"Введите время в часах, минутах и секундах (через двоеточие): ";
	wcin >> t2.hours >> colon >> t2.minutes >> colon >> t2.seconds;

	swap(t1, t2);

	// выводим отрезки времени на экран в исходном формате
	wcout << L"Первый отрезок времени: "
		<< t1.hours << L":" << t1.minutes << L":" << t1.seconds << endl;
	wcout << L"Второй отрезок времени: "
		<< t2.hours << L":" << t2.minutes << L":" << t2.seconds << endl;

	return 0;
}

// функция меняет местами значения двух заданных переменных
void swap(time& n1, time& n2)
{
	time temp;
	temp = n1; n1 = n2; n2 = temp;
}