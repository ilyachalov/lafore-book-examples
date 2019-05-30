// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 06chapter_10exercise.cpp
// Создать класс ship, представляющий корабль с информацией о его номере и координатах.
// Для задания номера корабля использовать механизм из упражнения 8 главы 6.
// Для координат использовать два поля класса angle из упражнения 7 главы 6.

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
#include <iomanip> // для манипулятора setprecision
using namespace std;

class angle // класс, представляющий широту или долготу координаты точки в морской навигации
{
private:
	int degrees;   // число градусов (1 градус = 60 минут)
	float minutes; // число минут (вместо секунд — разбивка на десятичные части минут)
	wchar_t dirLetter; // символ направления (N или S для широты; Е или W для долготы)
public:
	// конструктор без аргументов
	angle()
		{ }
	// конструктор с аргументами
	angle(int d, float m, wchar_t dl) : degrees(d), minutes(m), dirLetter(dl)
		{ }
	// метод для получения данных класса от пользователя с клавиатуры
	void get()
	{
		wcout << L"Введите число градусов, минут и символ направления: ";
		wcin >> degrees >> minutes >> dirLetter;
	}
	// константный метод выводит значения полей на экран
	void display() const
		{ wcout << degrees << L'\xB0' << fixed << setprecision(1) << minutes << L"\' " << dirLetter; }
};

class ship // класс, представляющий корабль
{
private:
	int number;       // учетный номер корабля
	static int count; // счетчик объектов класса (статическое поле класса)
	angle latitude;   // широта координаты расположения корабля
	angle longitude;  // и долгота
public:
	// конструктор без аргументов
	ship()
		{ count++; number = count; }
	// метод для получения данных класса от пользователя с клавиатуры
	void get()
	{
		wcout << L"Корабль № " << number << L". Введите координаты его расположения:\n";
		wcout << L"Широта. "; latitude.get();
		wcout << L"Долгота. "; longitude.get();
		wcout << endl;
	}
	// константный метод выводит поля объекта класса на экран
	void display() const
	{
		wcout << L"Корабль № " << number << L". Координаты его расположения:\n";
		wcout << L"широта: "; latitude.display();
		wcout << L", долгота: "; longitude.display();
		wcout << endl << endl;
	}
};

// инициализация статического поля класса
int ship::count = 0;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);
	
	ship s1, s2, s3; // создание трех объектов класса ship (то есть трех кораблей)

	// запрашиваем у пользователя информацию о каждом из кораблей
	s1.get();
	s2.get();
	s3.get();

	// выводим на экран информацию о трех кораблях
	s1.display();
	s2.display();
	s3.display();

	return 0;
}