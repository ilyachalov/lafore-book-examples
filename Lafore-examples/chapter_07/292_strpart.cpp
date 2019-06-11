// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// strpart.cpp
// использование строк как членов класса

// для использования небезопасной функции wcscpy
#define _CRT_SECURE_NO_WARNINGS

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
// #include <cstring> // для функции wcscpy (копирование строки) не понадобился
using namespace std;

class part           // класс, представляющий деталь изделия
{
private:
	wchar_t partname[30]; // название детали
	int partnumber;       // номер детали
	double cost;          // цена детали в рублях
public:
	void setpart(const wchar_t pname[], int pn, double c) // определение данных класса
	{
		wcscpy(partname, pname);
		// wcscpy_s(partname, 30, pname); // рекомендуемый более безопасный вариант
		partnumber = pn;
		cost = c;
	}
	void showpart() // вывод данных класса на экран
	{
		wcout << L"\nНазвание = \"" << partname;
		wcout << L"\", номер = " << partnumber;
		wcout << L", цена = " << cost << L" руб.";
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	part part1, part2; // создание двух объектов класса part

	// определение данных двух объектов
	part1.setpart(L"муфта", 4473, 217.55);
	part2.setpart(L"вороток", 9924, 419.25);

	// вывод данных двух объектов на экран
	wcout << L"Первая деталь: "; part1.showpart();
	wcout << L"\nВторая деталь: "; part2.showpart();
	wcout << endl;

	return 0;
}