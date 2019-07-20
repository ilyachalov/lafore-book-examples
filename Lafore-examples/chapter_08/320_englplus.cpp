// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// englplus.cpp
// перегрузка операции сложения (+) для сложения объектов класса Distance

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
	// сложение двух длин (перегрузка бинарной операции сложения)
	Distance operator+ (Distance) const; // прототип
};

// сложение двух длин (перегрузка бинарной операции сложения)
Distance Distance::operator+ (Distance d) const
{
	int f = feet + d.feet;       // складываем футы
	float i = inches + d.inches; // складываем дюймы
	if (i >= 12.0)               // если дюймов стало больше 12
	{
		i -= 12.0;               // то уменьшаем дюймы на 12
		f++;                     // и увеличиваем футы на 1
	}
	return Distance(f, i);       // создаем и возвращаем временную переменную
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	// определение трех длин с конструктором без аргументов
	Distance dist1, dist3, dist4;
	
	dist1.getdist(); // получим длину от пользователя с клавиатуры
	
	// определение и инициализация длины с конструктором с аргументами
	Distance dist2(11, 6.25);

	// складываем две длины с помощью перегруженной операции сложения (+)
	dist3 = dist1 + dist2;

	dist4 = dist1 + dist2 + dist3; // складываем несколько длин (объектов)

	// вывод всех длин на экран
	wcout << L"dist1 = "; dist1.showdist();
	wcout << L"\ndist2 = "; dist2.showdist();
	wcout << L"\ndist3 = "; dist3.showdist();
	wcout << L"\ndist4 = "; dist4.showdist();
	wcout << endl;

	return 0;
}