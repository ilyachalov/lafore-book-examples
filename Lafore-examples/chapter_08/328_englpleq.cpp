// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// englpleq.cpp
// перегрузка операции сложения с присвоением (+=) для объектов класса Distance

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
	// сложение с присвоением двух длин (перегрузка операции +=)
	void operator+= (Distance); // прототип
};

// сложение с присвоением двух длин (перегрузка операции +=)
void Distance::operator+= (Distance d)
{
	feet += d.feet;     // складываем футы
	inches += d.inches; // складываем дюймы
	if (inches >= 12.0) // если дюймов больше или равно 12
	{
		inches -= 12.0; // то уменьшаем дюймы на 12
		feet++;         // и увеличиваем футы на 1
	}
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	Distance dist1;  // определение длины с конструктором без аргументов
	dist1.getdist(); // получим длину от пользователя с клавиатуры
	wcout << L"dist1 = "; dist1.showdist(); // выведем на экран
	
	// определение и инициализация другой длины с конструктором с аргументами
	Distance dist2(11, 6.25);
	wcout << L"\ndist2 = "; dist2.showdist(); // выведем на экран

	// демонстрация сложения с присвоением для объектов класса Distance
	dist1 += dist2; // dist1 = dist1 + dist2
	wcout << L"\nПосле сложения с присвоением:";

	wcout << L"\ndist1 = "; dist1.showdist();
	wcout << endl;

	return 0;
}