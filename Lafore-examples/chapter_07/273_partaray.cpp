// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// partaray.cpp
// массив из структур

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

const int SIZE = 4; // количество элементов в массиве

struct part // структура, представляющая деталь
{
	int modelnumber; // номер модели изделия
	int partnumber;  // номер детали
	float cost;      // стоимость детали
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	int n;
	part apart[SIZE];
	
	// получение данных о деталях от пользователя и запись этих данных в массив
	for (n = 0; n < SIZE; n++)
	{
		wcout << L"Введите номер модели: ";
		wcin >> apart[n].modelnumber;
		wcout << L"Введите номер детали: ";
		wcin >> apart[n].partnumber;
		wcout << L"Введите стоимость: ";
		wcin >> apart[n].cost;
	}
	wcout << endl;

	// вывод элементов массива (структур, представляющих деталь) на экран
	for (n = 0; n < SIZE; n++)
	{
		wcout << L"Модель " << apart[n].modelnumber;
		wcout << L", деталь " << apart[n].partnumber;
		wcout << L", стоимость $" << apart[n].cost << endl;
	}

	return 0;
}