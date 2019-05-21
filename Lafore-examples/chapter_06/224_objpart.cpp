// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// objpart.cpp
// детали изделия в качестве объектов

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

class part           // определение класса
{
private:
	int modelnumber; // номер изделия
	int partnumber;  // номер детали
	float cost;      // стоимость детали
public:
	void setpart(int mn, int pn, float c) // установка данных
	{
		modelnumber = mn;
		partnumber = pn;
		cost = c;
	}
	void showpart()  // вывод данных
	{
		wcout << L"Модель " << modelnumber;
		wcout << L", деталь " << partnumber;
		wcout << L", стоимость $" << cost << endl;
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	part part1; // определение объекта класса part

	part1.setpart(6244, 373, 217.55F); // вызов метода
	part1.showpart();                  // вызов метода

	return 0;
}