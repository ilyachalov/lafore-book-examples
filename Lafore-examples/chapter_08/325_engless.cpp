// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// engless.cpp
// перегрузка операции «меньше чем» (<) для сравнения объектов класса Distance

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
	// сравнение двух длин, то есть перегрузка операции «меньше чем» (<)
	bool operator< (Distance) const; // прототип
};

// сравнение двух длин, то есть перегрузка операции «меньше чем» (<)
bool Distance::operator< (Distance d) const
{
	float bf1 = feet + inches / 12;
	float bf2 = d.feet + d.inches / 12;
	return (bf1 < bf2) ? true : false;
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	Distance dist1;  // определение длины с конструктором без аргументов
	dist1.getdist(); // получим длину от пользователя с клавиатуры
	
	// определение и инициализация длины с конструктором с аргументами
	Distance dist2(6, 2.5);

	wcout << L"dist1 = "; dist1.showdist();   // показываем длины на экране
	wcout << L"\ndist2 = "; dist2.showdist();

	// используем наш оператор
	if (dist1 < dist2)
		wcout << L"\ndist1 меньше чем dist2";
	else
		wcout << L"\ndist1 больше или равно чем dist2";
	wcout << endl;

	return 0;
}